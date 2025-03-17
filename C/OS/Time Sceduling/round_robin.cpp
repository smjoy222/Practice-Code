#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>

struct Process {
    int id;
    int arrivalTime;
    int burstTime;
    int remainingTime;
    int startTime;
    int completionTime;
    int waitingTime;
    int turnaroundTime;
    int responseTime;
    bool firstResponse; // To track if it's the first response
};

void calculateTimes(std::vector<Process>& processes, int timeSlice) {
    int n = processes.size();
    int currentTime = 0;
    std::vector<Process*> readyQueue;

    while (true) {
        // Add processes that have arrived to the ready queue
        for (auto& process : processes) {
            if (process.arrivalTime <= currentTime && process.remainingTime > 0 &&
                std::find(readyQueue.begin(), readyQueue.end(), &process) == readyQueue.end()) {
                readyQueue.push_back(&process);
            }
        }

        if (readyQueue.empty()) {
            if (std::all_of(processes.begin(), processes.end(), [](Process& p) { return p.remainingTime == 0; })) {
                break; // All processes completed
            }
            currentTime++; // Move time forward if no processes are ready
            continue;
        }

        // Process the first process in the ready queue
        Process* currentProcess = readyQueue.front();
        readyQueue.erase(readyQueue.begin());

        // Handle first response time
        if (currentProcess->firstResponse) {
            currentProcess->responseTime = currentTime - currentProcess->arrivalTime;
            currentProcess->firstResponse = false;
        }

        // Execute the process for the time slice or remaining time
        int timeToProcess = std::min(currentProcess->remainingTime, timeSlice);
        currentProcess->remainingTime -= timeToProcess;
        currentTime += timeToProcess;

        // If the process is completed
        if (currentProcess->remainingTime == 0) {
            currentProcess->completionTime = currentTime;
            currentProcess->turnaroundTime = currentProcess->completionTime - currentProcess->arrivalTime;
            currentProcess->waitingTime = currentProcess->turnaroundTime - currentProcess->burstTime;
        } else {
            readyQueue.push_back(currentProcess); // Add back to queue if not finished
        }
    }
}

void printProcesses(const std::vector<Process>& processes) {
    std::cout << "\nProcess ID | Arrival Time | Burst Time | Start Time | Completion Time | Waiting Time | Turnaround Time | Response Time\n";
    std::cout << "------------------------------------------------------------------------------------------------------\n";
    for (const auto& process : processes) {
        std::cout << std::setw(11) << process.id
                  << std::setw(14) << process.arrivalTime
                  << std::setw(12) << process.burstTime
                  << std::setw(12) << (process.startTime == -1 ? 0 : process.startTime)
                  << std::setw(16) << process.completionTime
                  << std::setw(12) << process.waitingTime
                  << std::setw(16) << process.turnaroundTime
                  << std::setw(14) << process.responseTime << "\n";
    }
}

int main() {
    int n, timeSlice;
    std::cout << "Enter the number of processes: ";
    std::cin >> n;

    std::vector<Process> processes(n);

    // Input process details
    for (int i = 0; i < n; ++i) {
        processes[i].id = i + 1;
        processes[i].firstResponse = true; // Initialize for response time calculation
        std::cout << "Enter arrival time and burst time for Process " << (i + 1) << ": ";
        std::cin >> processes[i].arrivalTime >> processes[i].burstTime;
        processes[i].remainingTime = processes[i].burstTime;
        processes[i].startTime = -1; // Mark as not yet set
    }

    std::cout << "Enter time slice: ";
    std::cin >> timeSlice;

    // Sort processes by arrival time initially
    std::sort(processes.begin(), processes.end(), [](Process a, Process b) {
        return a.arrivalTime < b.arrivalTime;
    });

    // Calculate times using Round Robin
    calculateTimes(processes, timeSlice);

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

