#include "Logger.h"
#include <iostream>


Logger::Logger(const std::string& filename, int minTaskTime, int maxTaskTime, int maxIpPart, bool verbose)
    : minTaskTime(minTaskTime), maxTaskTime(maxTaskTime), maxIpPart(maxIpPart), verbose(verbose) {
    logFile.open(filename);
    if (!logFile.is_open()) {
        printf("Error opening log file: %s\n", filename.c_str());
    }
    logFile << "Initialized Load Balancer." << std::endl;
    logFile << "Logger initialized with file: " << filename << std::endl;
    
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

void Logger::logStartup(int numServers, int totalCycles, int percentChanceGenerateRequest) {
    if (logFile.is_open()) {
        logFile << "Startup Parameters:" << std::endl;
        logFile << "Number of servers: " << numServers << std::endl;
        logFile << "Total cycles: " << totalCycles << std::endl;
        logFile << "Percent chance of generating a request each cycle: " << percentChanceGenerateRequest << "%" << std::endl;
        logFile << "Min Task Time: " << minTaskTime << ", Max Task Time: " << maxTaskTime << ", IP Segment Range: 0-" << maxIpPart << std::endl;
    } else {
        std::cerr << "Error: Log file is not open." << std::endl;
    }
}

void Logger::setStartingQueueSize(int size) {
    startingQueueSize = size;
    if (logFile.is_open()) {
        logFile << "Starting queue size: " << size << std::endl;
    }
}

void Logger::setEndingQueueSize(int size) {
    endingQueueSize = size;
    if (logFile.is_open()) {
        logFile << "Ending queue size: " << size << std::endl;
    }
}

void Logger::logCycle(int cycle, int queueSize) {
    if (logFile.is_open() && verbose) {
        logFile << "Cycle: " << cycle << ", Queue Size: " << queueSize << std::endl;
    }
}

void Logger::logAssignedRequest(int serverId, const std::string& ipIn, const std::string& ipOut, int time) {
    if (logFile.is_open() && verbose) {
        logFile << "  Assigned Request - Server ID: " << serverId << ", IP In: " << ipIn << ", IP Out: " << ipOut << ", Duration: " << time << std::endl;
    }
}

void Logger::logGeneratedRequest(const std::string& ipIn, const std::string& ipOut, int time) {
    if (logFile.is_open() && verbose) {
        logFile << "  Generated Request - IP In: " << ipIn << ", IP Out: " << ipOut << ", Duration: " << time << std::endl;
    }
}

void Logger::logServerAllocated(int serverIndex) {
    if (logFile.is_open()) {
        logFile << "--- Server Allocated - Index: " << serverIndex << " ---" << std::endl;
    }
}

void Logger::logServerDeallocated(int serverIndex) {
    if (logFile.is_open()) {
        logFile << "--- Server Deallocated - Index: " << serverIndex << " ---" << std::endl;
    }
}

void Logger::logFinalState(const std::vector<bool>& serverStatus, int queueSize) {
    if (logFile.is_open()) {
        logFile << "=== Final Simulation State ===" << std::endl;
        logFile << "Remaining Queue Size: " << queueSize << std::endl;
        logFile << "Active Servers: " << serverStatus.size() << std::endl;
        logFile << "Server Statuses:" << std::endl;

        for (size_t i = 0; i < serverStatus.size(); ++i) {
            logFile << "  Server " << i
                    << ": " << (serverStatus[i] ? "Busy" : "Idle") << std::endl;
        }

        // logFile << "Total Servers: " << serverStatus.size() << "\n";
        // logFile << "Idle Servers: "
        //         << std::count(serverStatus.begin(), serverStatus.end(), false) << "\n";
        // logFile << "Busy Servers: "
        //         << std::count(serverStatus.begin(), serverStatus.end(), true) << "\n";
    }
}
