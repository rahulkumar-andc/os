// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 04 - PART (ii)
//
// QUESTION:
// Write a program (using fork() and/or exec() commands) where parent and child execute:
//   ii. Same program, different code.
// ==============================================================================

#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    cout << "Initial Process PID: " << getpid() << endl;

    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Error: Fork failed." << endl;
        return 1;
    } 
    else if (pid == 0) {
        // Child Process executes this branch
        cout << "[Child Branch] PID: " << getpid() 
             << " | Parent PID: " << getppid() 
             << " -> Task: Computing square of 5 = " << (5 * 5) << endl;
    } 
    else {
        // Parent Process executes this branch
        cout << "[Parent Branch] PID: " << getpid() 
             << " | Created Child PID: " << pid 
             << " -> Task: Computing cube of 5 = " << (5 * 5 * 5) << endl;
    }

    return 0;
}
