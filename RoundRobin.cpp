// Round Robin scheduling
// Uses time quantum
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

class Process {
    public:
        int name = -1;
        int arrivalTime;
        int burstTime;
        int turnAroundTime;
        int waitingTime;
        int completionTime;
        int remainingTime;
        bool isComplete = false;
        bool isInReadyQueue = false;

    Process() {}
};

class Gantt {
    public:
        int name;
        int left;
        int right;
};

vector<Process> processList;
int numberOfProcesses;
int timeQuantum;

queue<Process> readyQueue; 

bool compareArrivalTime(Process p1, Process p2) {
    if(p1.arrivalTime == p2.arrivalTime) {
        return (p1.name < p2.name);
    }
    return (p1.arrivalTime < p2.arrivalTime);
}

vector<Gantt> ganttChart;

void displayGanttChart();
void calculateTAT();
void calculateWT();
void display();

int main() {
    
    cout << "Enter number of process: ";
    cin >> numberOfProcesses;

    cout << "Enter time quantum: ";
    cin >> timeQuantum;

    for(int i = 0; i < numberOfProcesses; i++) {
        Process currentProcess;
        currentProcess.name = i+1;

        cout << "P" << i+1 << " Arrival time: ";
        cin >> currentProcess.arrivalTime;

        cout << "P" << i+1 << " Burst time: ";
        cin >> currentProcess.burstTime;
        currentProcess.remainingTime = currentProcess.burstTime;

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
    int tempTimeQuantum = 1;
    Process previousProcess;
    bool isPreviousProcess = false;

    while(true) {
        if(tempTimeQuantum == 1) {
            for(int j = 0; j < numberOfProcesses; j++) {
                if(processList.at(j).arrivalTime <= tempBurstTime && processList.at(j).isComplete == false && !processList.at(j).isInReadyQueue) {
                    if(!isPreviousProcess || previousProcess.name != processList.at(j).name) {
                        processList.at(j).isInReadyQueue = true;
                        readyQueue.push(processList.at(j));            
                    } 
                }
            }
            if(isPreviousProcess) {
                readyQueue.push(previousProcess);
            }
        }

        if(readyQueue.empty()) {
            tempBurstTime++;
            continue;
        }

        Process current = readyQueue.front(); 

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
                    processList.at(i).isInReadyQueue = false;
                    processCount++;
                    tempTimeQuantum = 1;
                    readyQueue.pop();
                    isPreviousProcess = false;
                }
                else if(++tempTimeQuantum > timeQuantum) {
                    tempTimeQuantum = 1;
                    readyQueue.pop();
                    previousProcess = processList.at(i);
                    isPreviousProcess = true;
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