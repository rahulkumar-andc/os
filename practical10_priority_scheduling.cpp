// ==============================================================================
// UNIVERSITY OF DELHI - OPERATING SYSTEMS PRACTICAL LAB (GE / PME)
// PRACTICAL 10
//
// QUESTION:
// Write a program to implement non-preemptive priority-based scheduling algorithm.
// ==============================================================================

#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

struct Process {
    int pid;
    int burst_time;
    int priority;
    int waiting_time;
    int turnaround_time;
};

// Lower integer indicates higher scheduling priority
bool comparePriority(const Process &a, const Process &b) {
    if (a.priority == b.priority)
        return a.burst_time < b.burst_time;
    return a.priority < b.priority;
}

int main() {
    cout << "==========================================================" << endl;
    cout << "         NON-PREEMPTIVE PRIORITY CPU SCHEDULING           " << endl;
    cout << "==========================================================" << endl;

    int n;
    cout << "Enter number of processes: ";
    if (!(cin >> n) || n <= 0) {
        n = 4;
        cout << "\nUsing default count: 4" << endl;
    }

    vector<Process> p(n);
    vector<pair<int, int>> defaults = {{4, 2}, {3, 1}, {7, 4}, {2, 3}};

    for (int i = 0; i < n; i++) {
        p[i].pid = i + 1;
        cout << "P" << p[i].pid << " [Burst Time, Priority]: ";
        if (!(cin >> p[i].burst_time >> p[i].priority)) {
            p[i].burst_time = defaults[i % 4].first;
            p[i].priority = defaults[i % 4].second;
            cout << p[i].burst_time << " " << p[i].priority << " (auto)";
        }
    }

    // Sort according to priority
    sort(p.begin(), p.end(), comparePriority);

    p[0].waiting_time = 0;
    p[0].turnaround_time = p[0].burst_time;
    double total_wt = 0, total_tat = p[0].turnaround_time;

    for (int i = 1; i < n; i++) {
        p[i].waiting_time = p[i - 1].waiting_time + p[i - 1].burst_time;
        p[i].turnaround_time = p[i].waiting_time + p[i].burst_time;
        total_wt += p[i].waiting_time;
        total_tat += p[i].turnaround_time;
    }

    cout << "\n" << string(68, '-') << endl;
    cout << left << setw(10) << "Process" 
         << setw(12) << "Priority"
         << setw(14) << "Burst Time" 
         << setw(16) << "Waiting Time" 
         << setw(14) << "Turnaround" << endl;
    cout << string(68, '-') << endl;

    for (int i = 0; i < n; i++) {
        cout << left << setw(10) << ("P" + to_string(p[i].pid))
             << setw(12) << p[i].priority
             << setw(14) << p[i].burst_time
             << setw(16) << p[i].waiting_time
             << setw(14) << p[i].turnaround_time << endl;
    }
    cout << string(68, '-') << endl;

    cout << fixed << setprecision(2);
    cout << "Average Waiting Time    : " << (total_wt / n) << " ms" << endl;
    cout << "Average Turnaround Time : " << (total_tat / n) << " ms" << endl;
    cout << string(68, '-') << endl;

    return 0;
}
