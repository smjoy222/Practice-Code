#include <iostream>
#include <vector>
#include <algorithm>
#include <iomanip>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int priority;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

void calculateTimes(std::vector<Process>& processes) {
    int n = processes.size();
    int totalTime = 0;

    for (int i = 0; i < n; ++i) {
        totalTime += processes[i].burstTime;
    }

    // Initialize times
    for (auto& process : processes) {
        process.remainingTime = process.burstTime;
        process.startTime = -1; // Mark start time as not yet set
    }

    int currentTime = 0;
    int completed = 0;

    while (completed < n && currentTime <= totalTime) {
        // Find the available processes
        std::vector<Process*> availableProcesses;
        for (auto& process : processes) {
            if (process.arrivalTime <= currentTime && process.remainingTime > 0) {
                availableProcesses.push_back(&process);
            }
        }

        if (availableProcesses.empty()) {
            currentTime++;
            continue; // If no process is available, move time forward
        }

        // Sort available processes by priority
        auto highestPriorityProcess = std::min_element(availableProcesses.begin(), availableProcesses.end(),
            [](Process* a, Process* b) {
                return a->priority < b->priority;
            });

        // Execute the highest priority process
        Process* currentProcess = *highestPriorityProcess;
        if (currentProcess->startTime == -1) {
            currentProcess->startTime = currentTime; // Set start time on first execution
        }

        // Execute one time unit
        currentProcess->remainingTime--;
        currentTime++;

        // If process is completed
        if (currentProcess->remainingTime == 0) {
            currentProcess->completionTime = currentTime;
            currentProcess->turnaroundTime = currentProcess->completionTime - currentProcess->arrivalTime;
            currentProcess->waitingTime = currentProcess->turnaroundTime - currentProcess->burstTime;
            completed++;
        }
    }
}

void printProcesses(const std::vector<Process>& processes) {
    std::cout << "\nProcess ID | Arrival Time | Burst Time | Priority | Start Time | Completion Time | Waiting Time | Turnaround Time\n";
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    for (const auto& process : processes) {
        std::cout << std::setw(11) << process.id
                  << std::setw(14) << process.arrivalTime
                  << std::setw(12) << process.burstTime
                  << std::setw(10) << process.priority
                  << std::setw(12) << process.startTime
                  << std::setw(16) << process.completionTime
                  << std::setw(12) << process.waitingTime
                  << std::setw(16) << process.turnaroundTime << "\n";
    }
}

int main() {
    int n;
    std::cout << "Enter the number of processes preemptive priority scheduling: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        std::cout << "Enter arrival time, burst time, and priority for Process " << (i + 1) << ": ";
        std::cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
    }

    // Sort by arrival time initially
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    // Run the priority scheduling algorithm
    calculateTimes(processes);

    // Sort output by Process ID
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.id < b.id;
    });

    // Print the processes and their times
    printProcesses(processes);

    // Calculate average waiting time and average turnaround time
    float totalWT = 0, totalTAT = 0;
    for (const auto& process : processes) {
        totalWT += process.waitingTime;
        totalTAT += process.turnaroundTime;
    }

    float avgWT = totalWT / n;
    float avgTAT = totalTAT / n;

    // Throughput calculation
    int totalTime = processes.back().completionTime - processes.front().arrivalTime;
    float throughput = static_cast<float>(n) / totalTime;

    std::cout << "\nAverage Waiting Time: " << avgWT;
    std::cout << "\nAverage Turnaround Time: " << avgTAT;
    std::cout << "\nThroughput: " << throughput << " processes/unit time\n";

    return 0;
}

