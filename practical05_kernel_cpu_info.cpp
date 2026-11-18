// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 05
//
// QUESTION:
// Write a program to report behaviour of Linux kernel including kernel version,
// CPU type and CPU information.
// ==============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sys/utsname.h>

using namespace std;

int main() {
    cout << "==========================================================" << endl;
    cout << "          LINUX KERNEL & CPU DIAGNOSTIC REPORT            " << endl;
    cout << "==========================================================" << endl;

    // Part 1: Kernel & OS Details using uname system call
    struct utsname sys_info;
    if (uname(&sys_info) == 0) {
        cout << "Operating System  : " << sys_info.sysname << endl;
        cout << "Node Hostname     : " << sys_info.nodename << endl;
        cout << "Kernel Release    : " << sys_info.release << endl;
        cout << "Kernel Version    : " << sys_info.version << endl;
        cout << "Machine Arch      : " << sys_info.machine << endl;
    } else {
        perror("uname system call failed");
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "                 CPU HARDWARE SPECIFICATIONS              " << endl;
    cout << "----------------------------------------------------------" << endl;

    // Part 2: Extracting CPU details from /proc/cpuinfo
    ifstream cpuinfo("/proc/cpuinfo");
    if (!cpuinfo.is_open()) {
        cerr << "Failed to open /proc/cpuinfo" << endl;
        return 1;
    }

    string line;
    int model_count = 0;
    while (getline(cpuinfo, line)) {
        if (line.rfind("model name", 0) == 0 && model_count == 0) {
            cout << line << endl;
            model_count++;
        } else if (line.rfind("vendor_id", 0) == 0 && model_count <= 1) {
            cout << line << endl;
        } else if (line.rfind("cpu MHz", 0) == 0 && model_count <= 1) {
            cout << line << endl;
        } else if (line.rfind("cache size", 0) == 0 && model_count <= 1) {
            cout << line << endl;
            break;
        }
    }
    cpuinfo.close();

    cout << "==========================================================" << endl;
    return 0;
}
