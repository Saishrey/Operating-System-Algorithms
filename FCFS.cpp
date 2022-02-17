// FCFS
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

    for(int i = 0; i < numberOfProcesses; i++) {
        Gantt gantt;
        gantt.name = processList.at(i).name;
        gantt.left = tempBurstTime;
        tempBurstTime += processList.at(i).burstTime;
        gantt.right = tempBurstTime;
        ganttChart.push_back(gantt);

        processList.at(i).completionTime = tempBurstTime;
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