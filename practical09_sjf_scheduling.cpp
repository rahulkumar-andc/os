// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 09
//
// QUESTION:
// Write a program to implement Shortest Job First (SJF) scheduling algorithm
// (Non-Preemptive).
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;
    int burst_time;
    int waiting_time;
    int turnaround_time;
};

bool compareBurst(const Process &a, const Process &b) {
    return a.burst_time < b.burst_time;
}

int main() {
    cout << "==========================================================" << endl;
    cout << "      SHORTEST JOB FIRST (SJF) SCHEDULING (NON-PREEMPTIVE)" << endl;
    cout << "==========================================================" << endl;

    int n;
    cout << "Enter number of processes: ";
    if (!(cin >> n) || n <= 0) {
        n = 4;
        cout << "\nUsing default count: 4" << endl;
    }

    vector<Process> p(n);
    vector<int> default_bursts = {7, 3, 1, 5};

    cout << "Enter Burst Time for each process:" << endl;
    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << " Burst Time: ";
        if (!(cin >> p[i].burst_time)) {
            p[i].burst_time = (i < (int)default_bursts.size()) ? default_bursts[i] : (i + 2);
            cout << p[i].burst_time << " (auto)";
        }
    }

    // Sort processes by shortest burst time
    sort(p.begin(), p.end(), compareBurst);

    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    double total_wt = 0, total_tat = p[0].turnaround_time;

    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    cout << "\n" << string(58, '-') << endl;
    cout << left << setw(12) << "Process" 
         << setw(16) << "Burst Time" 
         << setw(16) << "Waiting Time" 
         << setw(14) << "Turnaround" << endl;
    cout << string(58, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(12) << ("P" + to_string(p[i].pid))
             << setw(16) << p[i].burst_time
             << setw(16) << p[i].waiting_time
             << setw(14) << p[i].turnaround_time << endl;
    }
    cout << string(58, '-') << endl;

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time    : " << (total_wt / n) << " ms" << endl;
    cout << "Average Turnaround Time : " << (total_tat / n) << " ms" << endl;
    cout << string(58, '-') << endl;

    return 0;
}
