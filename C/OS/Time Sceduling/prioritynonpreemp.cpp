
#include <iostream>
#include <vector>
#include <algorithm>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int priority;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
};

// Function to calculate start, completion, waiting, and turnaround times
void calculateTimes(std::vector<Process>& processes) {
    int n = processes.size();
    int currentTime = 0;

    for (int i = 0; i < n; ++i) {
        // If the current time is less than the arrival time, CPU remains idle until the next process arrives
        if (currentTime < processes[i].arrivalTime) {
            currentTime = processes[i].arrivalTime;
        }

        processes[i].startTime = currentTime;  // Process starts when the CPU becomes free
        currentTime += processes[i].burstTime;  // Current time moves forward based on the burst time
        processes[i].completionTime = currentTime;  // Completion time
        processes[i].turnaroundTime = processes[i].completionTime - processes[i].arrivalTime;  // TAT = CT - AT
        processes[i].waitingTime = processes[i].turnaroundTime - processes[i].burstTime;  // WT = TAT - BT
    }
}

// Function to implement Priority Scheduling (Non-preemptive)
void priorityScheduling(std::vector<Process>& processes) {
    int n = processes.size();

    // Sort processes by arrival time first, then by priority (lower priority value = higher priority)
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        if (a.arrivalTime == b.arrivalTime)
            return a.priority < b.priority;  // Prioritize based on the lowest priority number if arrival times are equal
        return a.arrivalTime < b.arrivalTime;
    });

    std::vector<Process> scheduled;
    int currentTime = 0;

    while (!processes.empty()) {
        // Find the processes that have arrived by the current time
        std::vector<Process> availableProcesses;
        for (const auto& process : processes) {
            if (process.arrivalTime <= currentTime) {
                availableProcesses.push_back(process);
            }
        }

        if (availableProcesses.empty()) {
            // If no process has arrived, move time forward to the next process's arrival time
            currentTime = processes[0].arrivalTime;
            continue;
        }

        // Find the process with the highest priority (lowest priority number) among available processes
        auto highestPriorityProcess = std::min_element(availableProcesses.begin(), availableProcesses.end(),
            [](Process a, Process b) {
                return a.priority < b.priority;
            });

        // Update current time and add the selected process to the scheduled list
        scheduled.push_back(*highestPriorityProcess);
        currentTime += highestPriorityProcess->burstTime;

        // Remove the selected process from the original list
        processes.erase(std::remove_if(processes.begin(), processes.end(),
            [&](Process p) { return p.id == highestPriorityProcess->id; }), processes.end());
    }

    // Calculate times for the scheduled processes
    calculateTimes(scheduled);

    // Sort output by Process ID to display processes in their original order
    std::sort(scheduled.begin(), scheduled.end(), [](Process a, Process b) {
        return a.id < b.id;
    });

    // Display the result
    std::cout << "\nProcess ID | Arrival Time | Burst Time | Priority | Start Time | Completion Time | Waiting Time | Turnaround Time\n";
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    for (const auto& process : scheduled) {
        std::cout << "    " << process.id << "        |      " << process.arrivalTime
                  << "       |     " << process.burstTime << "     |    " << process.priority
                  << "     |     " << process.startTime << "     |       " << process.completionTime
                  << "      |     " << process.waitingTime << "        |       " << process.turnaroundTime << "\n";
    }

    // Calculate average waiting time and average turnaround time
    float totalWT = 0, totalTAT = 0;
    for (const auto& process : scheduled) {
        totalWT += process.waitingTime;
        totalTAT += process.turnaroundTime;
    }

    float avgWT = totalWT / n;
    float avgTAT = totalTAT / n;

    // Throughput = total number of processes / (time of last completion - time of first arrival)
    int totalTime = scheduled.back().completionTime - scheduled.front().arrivalTime;
    float throughput = static_cast<float>(n) / totalTime;

    std::cout << "\nAverage Waiting Time: " << avgWT;
    std::cout << "\nAverage Turnaround Time: " << avgTAT;
    std::cout << "\nThroughput: " << throughput << " processes/unit time\n";
}

int main() {
    int n;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        std::cout << "Enter arrival time, burst time, and priority for Process " << (i + 1) << ": ";
        std::cin >> processes[i].arrivalTime >> processes[i].burstTime >> processes[i].priority;
    }

    priorityScheduling(processes);

    return 0;
}
