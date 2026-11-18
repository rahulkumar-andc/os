// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 06
//
// QUESTION:
// Write a program to report behaviour of Linux kernel including information on
// configured memory, amount of free and used memory. (Memory information)
// ==============================================================================

#include <iostream>
#include <fstream>
#include <string>
#include <sys/sysinfo.h>

using namespace std;

int main() {
    cout << "==========================================================" << endl;
    cout << "            SYSTEM MEMORY UTILIZATION REPORT              " << endl;
    cout << "==========================================================" << endl;

    // Method 1: Using POSIX sysinfo() system call
    struct sysinfo mem_info;
    if (sysinfo(&mem_info) == 0) {
        long long total_ram = mem_info.totalram * mem_info.mem_unit / (1024 * 1024);
        long long free_ram  = mem_info.freeram * mem_info.mem_unit / (1024 * 1024);
        long long used_ram  = total_ram - free_ram;

        cout << "Total Physical RAM  : " << total_ram << " MB" << endl;
        cout << "Free Physical RAM   : " << free_ram << " MB" << endl;
        cout << "Used Physical RAM   : " << used_ram << " MB" << endl;
        cout << "Shared Memory       : " << (mem_info.sharedram * mem_info.mem_unit / (1024 * 1024)) << " MB" << endl;
        cout << "Buffer Memory       : " << (mem_info.bufferram * mem_info.mem_unit / (1024 * 1024)) << " MB" << endl;
    } else {
        perror("sysinfo call failed");
    }

    cout << "----------------------------------------------------------" << endl;
    cout << "           DETAILED VALUES FROM /proc/meminfo             " << endl;
    cout << "----------------------------------------------------------" << endl;

    // Method 2: Extracting human-readable stats from /proc/meminfo
    ifstream memfile("/proc/meminfo");
    if (!memfile.is_open()) {
        cerr << "Failed to open /proc/meminfo" << endl;
        return 1;
    }

    string line;
    int count = 0;
    while (getline(memfile, line) && count < 6) {
        cout << line << endl;
        count++;
    }
    memfile.close();

    cout << "==========================================================" << endl;
    return 0;
}
