// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 12
//
// QUESTION:
// Write a program to implement first-fit, best-fit and worst-fit allocation strategies.
// ==============================================================================

#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

void printAllocation(const string &title, const vector<int> &blockSize, 
                     const vector<int> &processSize, const vector<int> &allocation) {
    cout << "\n--- " << title << " ---" << endl;
    cout << left << setw(14) << "Process No." 
         << setw(16) << "Process Size" 
         << setw(14) << "Block Allocated" << endl;
    cout << string(44, '-') << endl;

    for (size_t i = 0; i < processSize.size(); i++) {
        cout << left << setw(14) << ("P" + to_string(i + 1))
             << setw(16) << processSize[i];
        if (allocation[i] != -1)
            cout << setw(14) << ("Block " + to_string(allocation[i] + 1)) << endl;
        else
            cout << setw(14) << "Not Allocated" << endl;
    }
}

void firstFit(vector<int> blockSize, const vector<int> &processSize) {
    vector<int> allocation(processSize.size(), -1);
    for (size_t i = 0; i < processSize.size(); i++) {
        for (size_t j = 0; j < blockSize.size(); j++) {
            if (blockSize[j] >= processSize[i]) {
                allocation[i] = j;
                blockSize[j] -= processSize[i];
                break;
            }
        }
    }
    printAllocation("FIRST-FIT ALLOCATION RESULT", blockSize, processSize, allocation);
}

void bestFit(vector<int> blockSize, const vector<int> &processSize) {
    vector<int> allocation(processSize.size(), -1);
    for (size_t i = 0; i < processSize.size(); i++) {
        int bestIdx = -1;
        for (size_t j = 0; j < blockSize.size(); j++) {
            if (blockSize[j] >= processSize[i]) {
                if (bestIdx == -1 || blockSize[j] < blockSize[bestIdx]) {
                    bestIdx = j;
                }
            }
        }
        if (bestIdx != -1) {
            allocation[i] = bestIdx;
            blockSize[bestIdx] -= processSize[i];
        }
    }
    printAllocation("BEST-FIT ALLOCATION RESULT", blockSize, processSize, allocation);
}

void worstFit(vector<int> blockSize, const vector<int> &processSize) {
    vector<int> allocation(processSize.size(), -1);
    for (size_t i = 0; i < processSize.size(); i++) {
        int worstIdx = -1;
        for (size_t j = 0; j < blockSize.size(); j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    }
    printAllocation("WORST-FIT ALLOCATION RESULT", blockSize, processSize, allocation);
}

int main() {
    cout << "==========================================================" << endl;
    cout << "    CONTIGUOUS DYNAMIC MEMORY ALLOCATION SIMULATION       " << endl;
    cout << "==========================================================" << endl;

    vector<int> blockSize = {100, 500, 200, 300, 600};
    vector<int> processSize = {212, 417, 112, 426};

    cout << "Initial Memory Blocks (KB): ";
    for (int b : blockSize) cout << b << " ";
    cout << endl;

    cout << "Incoming Processes    (KB): ";
    for (int p : processSize) cout << p << " ";
    cout << endl;

    firstFit(blockSize, processSize);
    bestFit(blockSize, processSize);
    worstFit(blockSize, processSize);

    cout << "\n==========================================================" << endl;
    return 0;
}
