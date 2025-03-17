
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Process {
    int id;    // Process ID
    int at;    // Arrival Time
    int bt;    // Burst Time
    int st;    // Start Time
    int wt;    // Waiting Time
    int tat;   // Turnaround Time
    int ct;    // Completion Time
};

int main() {
    int n;
    cout << "Enter the number of processes: ";
    cin >> n;

    vector<Process> processes(n);

    // Input arrival time and burst time for each process
    cout << "Enter Arrival Time and Burst Time:\n";
    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << " (AT BT): ";
        cin >> processes[i].at >> processes[i].bt;
        processes[i].id = i + 1;  // Assign process ID
    }

    // Sort processes based on arrival time and then burst time (SJF non-preemptive)
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        if (a.at == b.at) return a.bt < b.bt;  // If arrival times are the same, prioritize by burst time
        return a.at < b.at;
    });

    int current_time = 0;
    int total_wt = 0, total_tat = 0;

    // Process completion and waiting times
    for (int i = 0; i < n; i++) {
        // Process starts after the current time or its own arrival time, whichever is larger
        if (current_time < processes[i].at) {
            current_time = processes[i].at;
        }
        processes[i].st = current_time; // Start time is the current time
        processes[i].ct = current_time + processes[i].bt;  // Completion time
        processes[i].tat = processes[i].ct - processes[i].at;  // Turnaround time = Completion time - Arrival time
        processes[i].wt = processes[i].st - processes[i].at;   // Waiting time = Start time - Arrival time

        total_wt += processes[i].wt;
        total_tat += processes[i].tat;

        current_time = processes[i].ct;  // Update current time after the process completes
    }

    // Sort output by Process ID
    sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.id < b.id;
    });

    // Print the process details
    cout << "\nP\tAT\tBT\tST\tCT\tWT\tTAT\n";
    for (const auto& p : processes) {
        cout << "P" << p.id << "\t" << p.at << "\t" << p.bt << "\t" << p.st << "\t" << p.ct << "\t" << p.wt << "\t" << p.tat << endl;
    }

    // Calculate averages
    float avg_wt = (float)total_wt / n;
    float avg_tat = (float)total_tat / n;

    // Throughput = total number of processes / (time of last completion - time of first arrival)
    int total_time = processes[n - 1].ct - processes[0].at;
    float throughput = (float)n / total_time;

    // Print averages and throughput
    cout << "\nAverage Waiting Time: " << avg_wt << endl;
    cout << "Average Turnaround Time: " << avg_tat << endl;
    cout << "Throughput: " << throughput << " processes/unit time" << endl;

    return 0;
}

