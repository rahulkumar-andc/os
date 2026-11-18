// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 04 - PART (iii)
//
// QUESTION:
// Write a program (using fork() and/or exec() commands) where parent and child execute:
//   iii. Before terminating, the parent waits for the child to finish its task.
// ==============================================================================

#include <iostream>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

using namespace std;

int main() {
    cout << "[Parent PID: " << getpid() << "] Creating a child process..." << endl;

    pid_t pid = fork();

    if (pid < 0) {
        cerr << "Fork failed." << endl;
        return 1;
    } 
    else if (pid == 0) {
        // Child Process
        cout << "[Child PID: " << getpid() << "] Working on heavy task (sleeping 2 seconds)..." << endl;
        sleep(2);
        cout << "[Child PID: " << getpid() << "] Task completed. Exiting now." << endl;
        _exit(42); // Exit with status code 42
    } 
    else {
        // Parent Process
        cout << "[Parent PID: " << getpid() << "] Waiting for child (PID: " << pid << ") to complete..." << endl;
        
        int status;
        pid_t terminated_child = waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            cout << "[Parent PID: " << getpid() << "] Child process " << terminated_child 
                 << " terminated normally with exit status: " << WEXITSTATUS(status) << endl;
        }
        cout << "[Parent] Execution finished." << endl;
    }

    return 0;
}
