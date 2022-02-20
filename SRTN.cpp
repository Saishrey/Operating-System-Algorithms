// SRTN
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
    public:
        int name;
        int arrivalTime;
        int burstTime;
        int turnAroundTime;
        int waitingTime;
        int completionTime;
        int remainingTime;
        bool isComplete = false;
};

class Gantt {
    public:
        int name;
        int left;
        int right;
};

vector<Process> processList;
int numberOfProcesses;

bool compareArrivalTime(Process p1, Process p2) {
    return (p1.arrivalTime < p2.arrivalTime);
}

bool compareRemainingTime(Process p1, Process p2) {
    return (p1.remainingTime < p2.remainingTime);
}

vector<Gantt> ganttChart;

void displayGanttChart();
void calculateTAT();
void calculateWT();
void display();

int main() {
    
    cout << "Enter number of process: ";
    cin >> numberOfProcesses;

    for(int i = 0; i < numberOfProcesses; i++) {
        Process currentProcess;
        currentProcess.name = i+1;
        cout << "P" << i+1 << " Burst time: ";
        cin >> currentProcess.burstTime;
        currentProcess.remainingTime = currentProcess.burstTime;
        
        cout << "P" << i+1 << " Arrival time: ";
        cin >> currentProcess.arrivalTime;

        processList.push_back(currentProcess);

        cout << endl;
    }

    sort(processList.begin(), processList.end(), compareArrivalTime);

    displayGanttChart();
    calculateTAT();
    calculateWT();
    display();

    return 0;
}

void displayGanttChart() {
    int tempBurstTime = processList.at(0).arrivalTime;
    int processCount = 0;
    while(true) {
        vector<Process> tempList;
        for(int j = 0; j < numberOfProcesses; j++) {
            if(processList.at(j).arrivalTime <= tempBurstTime && processList.at(j).isComplete == false) {
                tempList.push_back(processList.at(j));
            }
        }

        if(tempList.size() == 0 && processCount < numberOfProcesses) {
            tempBurstTime++;
            continue;
        }

        sort(tempList.begin(), tempList.end(), compareRemainingTime);

        Process current = tempList.at(0);

        Gantt gantt;
        gantt.name = current.name;
        gantt.left = tempBurstTime;
        gantt.right = ++tempBurstTime;
        ganttChart.push_back(gantt);

        

        for(int i = 0; i < numberOfProcesses; i++) {
            if(processList.at(i).name == current.name) {

                processList.at(i).remainingTime--;

                if(processList.at(i).remainingTime == 0) {
                    processList.at(i).completionTime = tempBurstTime;
                    processList.at(i).isComplete = true;
                    processCount++;
                }
                break;
            }
        }

        if(processCount == numberOfProcesses) {
            break;
        }
    }

    cout << "Gantt chart: ";
    for(Gantt current : ganttChart) {
        cout << "|" << current.left << " P" << current.name << " " << current.right << "|";
    }
}

void calculateTAT() {
    for(int i = 0; i < numberOfProcesses; i++) {
        processList.at(i).turnAroundTime = processList.at(i).completionTime - processList.at(i).arrivalTime;
    }
}

void calculateWT() {
    for(int i = 0; i < numberOfProcesses; i++) {
        processList.at(i).waitingTime = processList.at(i).turnAroundTime - processList.at(i).burstTime;
    }
}

void display() {

    float totalTAT = 0;
    float avgWT = 0;
    cout << endl << "Process\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\tCompletion Time" << endl;

    for(Process p : processList) {
        cout << "P" << p.name << "\t\t" << p.arrivalTime << "\t\t" << p.burstTime << "\t\t" << p.waitingTime << "\t\t" << p.turnAroundTime << "\t\t" << p.completionTime<< endl;
        totalTAT += (float)p.turnAroundTime;
        avgWT += (float)p.waitingTime;
    }

    cout << "\nTotal turn around time: " << totalTAT << endl;

    avgWT/=numberOfProcesses;

    cout << "\nAverage waiting time: " << avgWT << endl;


}