/* Banker's Algorithm */
/* 
    numberOfProcesses = 3                          5
    numberOfResources = 3                          3

    Allocation =        2 2 3 2 0 3 1 2 4          0 1 0 2 0 0 3 0 2 2 1 1 0 0 2
    Max =               3 6 8 4 3 3 3 4 4          7 5 3 3 2 2 9 0 2 2 2 2 4 3 3
    available =         7 7 10                     3 3 2

    4
    3
    1 0 1 2 1 2 3 0 0 1 0 1
    2 1 1 5 4 4 3 1 1 1 1 1
    2 1 1
    3
    1 0 1

    5
    4
    0 0 1 2 1 0 0 0 1 3 5 4 0 6 3 2 0 0 1 4
    0 0 1 2 1 7 5 0 2 3 5 6 0 6 5 2 0 6 5 6
    1 5 2 0
    2
    0 4 2 0

*/
#include <iostream>
#include <vector>
#define MAX 100
using namespace std;

int numberOfProcesses;
int numberOfResources;
int allocation[MAX][MAX];
int max_need[MAX][MAX];
int need[MAX][MAX];
int available[MAX][MAX];
vector<int> safeSequence;
bool isSafe = true;

void findNeedMatrix();
void checkSafeState();
void display();

int main() {

    cout << "Enter the number of processes: ";
    cin >> numberOfProcesses;

    cout << "Enter the number of Resources: ";
    cin >> numberOfResources;

    cout << "Enter the allocation Matrix: " << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfResources; j++) {
            cin >> allocation[i][j];
        }
    }

    cout << "Enter the maximum need Matrix: " << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfResources; j++) {
            cin >> max_need[i][j];
        }
    }

    cout << "Enter available string: ";
    for (int i = 0; i < numberOfResources; i++) {
        cin >> available[0][i];
    }

    findNeedMatrix();

    checkSafeState();

    display();

    // Check if request can be granted
    int requestProcess;
    cout << endl << "Enter process name for which request is to granted(int value): ";
    cin >> requestProcess;

    int request[numberOfResources];
    cout << "Enter the request string: ";
    for (int i = 0; i < numberOfResources; i++) {
        cin >> request[i];
    }

    bool checkRequest = true;
    for (int i = 0; i < numberOfResources; i++) {
        if(request[i] > need[requestProcess-1][i] || request[i] > available[0][i]) {
            checkRequest = false;
            break;
        }
    }

    if(checkRequest) {
        cout << "Request can be granted." << endl;

        for (int i = 0; i < numberOfResources; i++) {
            allocation[requestProcess-1][i] += request[i];
            available[0][i] -= request[i];
            need[requestProcess-1][i] -= request[i];
        }

        for (int i = 0; i < numberOfProcesses; i++) {
            need[i][numberOfResources] = 0;
        }

        safeSequence.clear();
        
        findNeedMatrix();

        checkSafeState();

        display();   
    }
    else {
        cout << "Request CANNOT be granted." << endl;
    }
    


    return 0;
}

void findNeedMatrix() {
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfResources; j++) {
            need[i][j] = max_need[i][j] - allocation[i][j];
        }
        need[i][numberOfResources] = 0;
    }
}

void checkSafeState() {
    int availableIndex = 0;
    
    while (availableIndex < numberOfProcesses) {
        bool checkProcess = false;

        for (int i = 0; i < numberOfProcesses; i++) {

            if(need[i][numberOfResources] == 1) { // If process has already exited
                continue;
            }

            bool flag = true;
            for (int j = 0; j < numberOfResources; j++) {
                if(available[availableIndex][j] < need[i][j]) {
                    flag = false;
                    break;
                }
            }

            if(flag) {
                checkProcess = true;
                need[i][numberOfResources] = 1;
                availableIndex++;
                for (int c = 0; c < numberOfResources; c++) {
                    available[availableIndex][c] = available[availableIndex-1][c] + allocation[i][c];
                }
                safeSequence.push_back(i+1);
                break;
            }
        }

        if (!checkProcess) {
            isSafe = false;
            return;
        }
        
    }
    
}

void display() {
    cout << "Allocation: " << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfResources; j++) {
            cout << allocation[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Max: " << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfResources; j++) {
            cout << max_need[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl << "Need: " << endl;
    for (int i = 0; i < numberOfProcesses; i++) {
        for (int j = 0; j < numberOfResources; j++) {
            cout << need[i][j] << " ";
        }
        cout << endl;
    }

    if(isSafe) {
        cout << endl << "System is in safe state.";

        cout << endl << "Safe Sequence: ";
        for(int i = 0; i < (int)safeSequence.size(); i++) {
            cout << "P" << safeSequence.at(i) << " ";
        }

        

        cout << endl << "Available: " << endl;
        for (int i = 0; i <= numberOfProcesses; i++) {
            if (i == numberOfProcesses) {
                for (int c = 0; c < numberOfResources; c++) {
                    cout << "__";
                }
                cout << endl;
            }
            for (int j = 0; j < numberOfResources; j++) {
                cout << available[i][j] << " ";
            }
            cout << endl;
        }

        
    }
    else {
        cout << endl << "System is unsafe.";
    }

}
