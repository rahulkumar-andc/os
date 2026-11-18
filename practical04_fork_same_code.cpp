// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 04 - PART (i)
//
// QUESTION:
// Write a program (using fork() and/or exec() commands) where parent and child execute:
//   i. Same program, same code.
// ==============================================================================

#include <iostream>
#include <unistd.h>
#include <sys/types.h>

using namespace std;

int main() {
    cout << "[Parent PID: " << getpid() << "] Invoking fork()..." << endl;

    // fork() duplicates the calling process
    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Error: Fork failed to create child process." << endl;
        return 1;
    }

    // Both parent and child execute the exact same block of code
    cout << "Process Execution -> PID: " << getpid() 
         << " | Parent PID (PPID): " << getppid() << endl;

    return 0;
}
