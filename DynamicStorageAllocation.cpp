// First Fit algo
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Process {
    public:
        int name;
        int size;
        bool isAllocated = false;
        int allocatedBlockNum;
};

class Block {
    public:
        int blockNum;
        int totalBlockSize;
        int remainingBlockSize;
};

vector<Process> processList;
vector<Block> blockList;
int numberOfBlocks;
int numberOfProcesses;

void display(vector<Process> p, vector<Block> b);

vector<Process> processListFF;
vector<Block> blockListFF;
void firstFit();

vector<Process> processListBF;
vector<Block> blockListBF;
void bestFit();

vector<Process> processListWF;
vector<Block> blockListWF;
void worstFit();

bool compareBlock(Block b1, Block b2) {
    return (b1.remainingBlockSize < b2. remainingBlockSize);
}

int main() {

    cout << "Enter number of unallocated blocks: ";
    cin >> numberOfBlocks;

    cout << "Enter size of each block: ";
    for (int i = 0; i < numberOfBlocks; i++) {
        Block newBlock;
        newBlock.blockNum = i+1;
        cin >> newBlock.totalBlockSize;
        newBlock.remainingBlockSize = newBlock.totalBlockSize;
        blockList.push_back(newBlock);
    }


    cout << "Enter number of processes: ";
    cin >> numberOfProcesses;
    
    cout << "Enter size of process: ";
    for (int i = 0; i < numberOfProcesses; i++) {
        Process newProcess;
        newProcess.name = i+1;
        cin >> newProcess.size;

        processList.push_back(newProcess);
    }
    
    firstFit();

    bestFit();

    worstFit();

    return 0;
}

void display(vector<Process> p, vector<Block> b) {
    cout << "Process\tProcess size\tAllocated Block\tTotal block size\tRemaining block size" << endl;
     
    for (int i = 0; i < numberOfProcesses; i++) {
        cout << "P" << p.at(i).name << "\t\t" << p.at(i).size << "\t\t";

        if(p.at(i).isAllocated) {
            cout << p.at(i).allocatedBlockNum;

            for (int j = 0; j < numberOfBlocks; j++) {
                if(b.at(j).blockNum == p.at(i).allocatedBlockNum) {
                    cout << "\t\t" << b.at(j).totalBlockSize << "\t\t" << b.at(j).remainingBlockSize << endl;
                    break;
                }
            }
            
        } 
        else {
            cout << "Unallocated" << "\t---\t\t---" << endl;
        }

    }
    
}

void firstFit() {
    processListFF = processList;
    blockListFF = blockList;

    cout << endl << "First Fit: " << endl;

    for(int i = 0; i < numberOfProcesses; i++) {
        for(int j = 0; j < numberOfBlocks; j++) {
            if(processListFF.at(i).size <= blockListFF.at(j).remainingBlockSize) {
                processListFF.at(i).isAllocated = true;
                blockListFF.at(j).remainingBlockSize -= processListFF.at(i).size;
                processListFF.at(i).allocatedBlockNum = blockListFF.at(j).blockNum;
                break;
            }
        }
    }

    display(processListFF, blockListFF);
}

void bestFit() {
    processListBF = processList;
    blockListBF = blockList;
    
    cout << endl << "Best Fit: " << endl;

    for(int i = 0; i < numberOfProcesses; i++) {
        sort(blockListBF.begin(), blockListBF.end(), compareBlock);
        for(int j = 0; j < numberOfBlocks; j++) {
            
            if(processListBF.at(i).size <= blockListBF.at(j).remainingBlockSize) {
                processListBF.at(i).isAllocated = true;
                blockListBF.at(j).remainingBlockSize -= processListBF.at(i).size;
                processListBF.at(i).allocatedBlockNum = blockListBF.at(j).blockNum;
                break;
            }
        }
    }

    display(processListBF, blockListBF);
}

void worstFit() {
    processListWF = processList;
    blockListWF = blockList;
    
    cout << endl << "Worst Fit: " << endl;

    for(int i = 0; i < numberOfProcesses; i++) {
        sort(blockListWF.begin(), blockListWF.end(), compareBlock);
        for(int j = numberOfBlocks-1; j >= 0; j--) {
            
            if(processListWF.at(i).size <= blockListWF.at(j).remainingBlockSize) {
                processListWF.at(i).isAllocated = true;
                blockListWF.at(j).remainingBlockSize -= processListWF.at(i).size;
                processListWF.at(i).allocatedBlockNum = blockListWF.at(j).blockNum;
                break;
            }
        }
    }

    display(processListWF, blockListWF);
}