#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Process {
    int id;                 // Process ID
    int at;                 // Arrival Time
    int bt;                 // Burst Time
    int remaining_time;     // Remaining Time
    int completion_time;    // Completion Time
    int waiting_time;       // Waiting Time
    int turnaround_time;    // Turnaround Time
    int start_time;         // Start Time
    int response_time;      // Response Time
};

bool compareByArrival(Process a, Process b) {
    return a.at < b.at;
}

bool compareByID(Process a, Process b) {
    return a.id < b.id;
}

void calculateSJFPreemptive(std::vector<Process>& processes) {
    int n = processes.size();
    int current_time = 0;
    int completed = 0;

    // Initialize remaining times and start times
    for (auto& process : processes) {
        process.remaining_time = process.bt;
        process.start_time = -1; // Initialize start_time
    }

    while (completed < n) {
        // Find all processes that have arrived by current_time
        std::vector<Process*> ready_queue;

        for (auto& process : processes) {
            if (process.at <= current_time && process.remaining_time > 0) {
                ready_queue.push_back(&process);
            }
        }

        if (ready_queue.empty()) {
            // If no process is ready, just move time forward
            current_time++;
            continue;
        }

        // Sort by remaining time (SJF)
        std::sort(ready_queue.begin(), ready_queue.end(),
                  [](Process* a, Process* b) { return a->remaining_time < b->remaining_time; });

        // Execute the process with the smallest remaining time
        Process* current_process = ready_queue[0];

        // Set the start time if it's the first time the process is being executed
        if (current_process->start_time == -1) {
            current_process->start_time = current_time;
            current_process->response_time = current_time - current_process->at;  // Calculate Response Time
        }

        current_process->remaining_time--;
        current_time++;

        // If the process is completed
        if (current_process->remaining_time == 0) {
            current_process->completion_time = current_time;
            current_process->turnaround_time = current_process->completion_time - current_process->at;
            current_process->waiting_time = current_process->turnaround_time - current_process->bt;
            completed++;
        }
    }
}

void printProcessDetails(const std::vector<Process>& processes) {
    std::cout << std::setw(10) << "Process ID"
              << std::setw(10) << "AT"
              << std::setw(10) << "BT"
              << std::setw(20) << "Start Time"
              << std::setw(20) << "Completion Time"
              << std::setw(20) << "Turnaround Time"
              << std::setw(20) << "Waiting Time"
              << std::setw(20) << "Response Time" << std::endl;

    for (const auto& process : processes) {
        std::cout << std::setw(10) << process.id
                  << std::setw(10) << process.at
                  << std::setw(10) << process.bt
                  << std::setw(20) << process.start_time
                  << std::setw(20) << process.completion_time
                  << std::setw(20) << process.turnaround_time
                  << std::setw(20) << process.waiting_time
                  << std::setw(20) << process.response_time << std::endl;
    }
}

void calculateAveragesAndThroughput(const std::vector<Process>& processes) {
    int total_turnaround_time = 0;
    int total_waiting_time = 0;
    int n = processes.size();

    for (const auto& process : processes) {
        total_turnaround_time += process.turnaround_time;
        total_waiting_time += process.waiting_time;
    }

    double avg_turnaround_time = (double)total_turnaround_time / n;
    double avg_waiting_time = (double)total_waiting_time / n;

    // Throughput is number of processes / total time taken
    int total_time = processes.back().completion_time - processes.front().at;
    double throughput = (double)n / total_time;

    std::cout << "\nAverage Turnaround Time: " << avg_turnaround_time << std::endl;
    std::cout << "Average Waiting Time: " << avg_waiting_time << std::endl;
    std::cout << "Throughput: " << throughput << " processes/unit time" << std::endl;
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1; // Assign process ID
        std::cout << "Enter arrival time and burst time for process " << (i + 1) << ": ";
        std::cin >> processes[i].at >> processes[i].bt;
    }

    // Sort processes by arrival time
    std::sort(processes.begin(), processes.end(), compareByArrival);

    calculateSJFPreemptive(processes);

    // Sort processes by process ID for output
    std::sort(processes.begin(), processes.end(), compareByID);

    printProcessDetails(processes);

    // Calculate and display averages and throughput
    calculateAveragesAndThroughput(processes);

    return 0;
}
