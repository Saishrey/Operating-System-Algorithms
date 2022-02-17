/* Page replacement algorithm
    FIFO
    LRU
    Optimal
    
    length 12
    1 2 3 4 5 1 3 1 6 3 2 3
    framesize 3

    length 10
    4 7 6 1 7 6 1 2 7 2
    framesize 4

    length 20
    1 2 3 4 2 1 5 6 2 1 2 3 7 6 3 2 1 2 3 6

*/

#include <iostream>
#include <vector>
#define MAX 100

using namespace std;

int length;
vector<string> referenceString;
int frameSize;
string memoryFIFO[MAX][MAX];
string memoryLRU[MAX][MAX];
string memoryOptimal[MAX][MAX];

vector<char> pageFaultListFIFO;
vector<char> pageFaultListLRU;
vector<char> pageFaultListOptimal;

void display(string mem[MAX][MAX], vector<char> pgflt);

void fifo();
void lru();
void optimal();

int main() {

    cout << "Length of reference string: ";
    cin >> length;

    cout << "Enter the reference string: ";
    for (int i = 0; i < length; i++) {
        string val;
        cin >> val;
        referenceString.push_back(val);
    }

    cout << "Number of frames: ";
    cin >> frameSize;
    
    fifo();

    lru();

    optimal();

    return 0;
}

void fifo() {
    cout << endl << "FIFO: " << endl;

    int countFifo = 0;
    bool isPagefault;

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < frameSize; j++) {
            memoryFIFO[i][j] = " ";
        }
    }

    for (int i = 0; i < length; i++) {
        for(int k = 0; k < frameSize && i > 0; k++) {
            memoryFIFO[i][k] = memoryFIFO[i-1][k];
        }
        isPagefault = true;
        for (int j = 0; j < frameSize; j++) {
            if(referenceString.at(i) == memoryFIFO[i][j]) {
                isPagefault = false;
                break;
            }
        }
        if (isPagefault) {
            memoryFIFO[i][countFifo%frameSize] = referenceString.at(i);
            pageFaultListFIFO.push_back('*');
            countFifo++;
        }
        else {
            pageFaultListFIFO.push_back('H');
        }
    }

    display(memoryFIFO, pageFaultListFIFO);
    
}

void lru() {
    cout << endl << "LRU: " << endl;

    int countLRU = 0;

    vector<string> tempLRU;

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < frameSize; j++) {
            memoryLRU[i][j] = " ";
        }
    }

    for (int i = 0; i < length; i++) {
        
        for(int k = 0; k < frameSize && i > 0; k++) {
            memoryLRU[i][k] = memoryLRU[i-1][k];
        }
        
        bool isPagefault = true;
        for (int j = 0; j < frameSize; j++) {
            if(referenceString.at(i) == memoryLRU[i][j]) {
                isPagefault = false;
                break;
            }
        }
        if (isPagefault) {
            if (countLRU < frameSize) {
                memoryLRU[i][countLRU] = referenceString.at(i);
                countLRU++;
            }
            else {
                for(int c = 0; c < frameSize; c++) {
                    if(memoryLRU[i][c] == tempLRU.front()) {
                        memoryLRU[i][c] = referenceString.at(i);
                        tempLRU.erase(tempLRU.begin());
                        break;
                    }
                }
            }
            pageFaultListLRU.push_back('*');
        }
        else {
            pageFaultListLRU.push_back('H');
        }

        for(int k = 0; k < tempLRU.size(); k++) {
            if(tempLRU.at(k) == referenceString.at(i)) {
                tempLRU.erase(tempLRU.begin() + k);
            }
        }
        tempLRU.push_back(referenceString.at(i));
    }

    display(memoryLRU, pageFaultListLRU);  
}

void optimal() {
    cout << endl << "Optimal: " << endl;

    int countOptimal= 0;

    for(int i = 0; i < length; i++) {
        for(int j = 0; j < frameSize; j++) {
            memoryOptimal[i][j] = " ";
        }
    }

    for (int i = 0; i < length; i++) {
        
        for(int k = 0; k < frameSize && i > 0; k++) {
            memoryOptimal[i][k] = memoryOptimal[i-1][k];
        }
        
        bool isPagefault = true;
        for (int j = 0; j < frameSize; j++) {
            if(referenceString.at(i) == memoryOptimal[i][j]) {
                isPagefault = false;
                break;
            }
        }
        if (isPagefault) {
            if (countOptimal < frameSize) {
                memoryOptimal[i][countOptimal] = referenceString.at(i);
                countOptimal++;
            }
            else {
                int farthest = i+1;
                int res = -1;
                bool pageFound = false;
                for (int f = 0; f < frameSize; f++) {
                    int p;
                    for (p = i+1; p < length; p++) {
                        if (memoryOptimal[i][f] == referenceString.at(p)) {
                            if (p > farthest) {
                                farthest = p;
                                res = f;
                            }
                            break;
                        }
                    }

                    if(p == length) {
                        memoryOptimal[i][f] = referenceString.at(i);
                        pageFound = true;
                        break;
                    }
                    
                }

                if(!pageFound && res == -1) {
                    memoryOptimal[i][0] = referenceString.at(i);
                }
                else if (!pageFound && res > -1) {
                    memoryOptimal[i][res] = referenceString.at(i);
                }
                
            }
            pageFaultListOptimal.push_back('*');
        }
        else {
            pageFaultListOptimal.push_back('H');
        }

    }

    display(memoryOptimal, pageFaultListOptimal); 
}

void display(string mem[MAX][MAX], vector<char> pgflt) {
    cout << "* => Page miss\nH => Page hit\n\n| ";

    for(int i = 0; i < length; i++) {
        cout << referenceString.at(i) << " | ";
    }

    cout << endl << endl;

    for (int i = 0; i < frameSize; i++) {
        cout << "| ";
        for (int j = 0; j < length; j++) {
            cout << mem[j][i] << " | ";
        }
        cout << endl;
    }
    
    cout << endl << "| ";

    int pageFaultCount = 0;
    
    for (int i = 0; i < length; i++) {
        if(pgflt.at(i) == '*') {
            pageFaultCount++;
        }
        cout << pgflt.at(i) << " | ";
    }
    
    cout << endl << "Page Faults = " << pageFaultCount << endl;
}