#include "Logger.h"
#include <iostream>


Logger::Logger(const std::string& filename, int minTaskTime, int maxTaskTime, int maxIpPart)
    : minTaskTime(minTaskTime), maxTaskTime(maxTaskTime), maxIpPart(maxIpPart) {
    logFile.open(filename);
    if (!logFile.is_open()) {
        printf("Error opening log file: %s\n", filename.c_str());
    }
}

Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
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
    if (logFile.is_open()) {
        logFile << "Cycle: " << cycle << ", Queue Size: " << queueSize << std::endl;
    }
}

void Logger::logAssignedRequest(int serverId, const std::string& ipIn, const std::string& ipOut, int time) {
    if (logFile.is_open()) {
        logFile << "Assigned Request - Server ID: " << serverId << ", IP In: " << ipIn << ", IP Out: " << ipOut << ", Duration: " << time << std::endl;
    }
}

void Logger::logGeneratedRequest(const std::string& ipIn, const std::string& ipOut, int time) {
    if (logFile.is_open()) {
        logFile << "Generated Request - IP In: " << ipIn << ", IP Out: " << ipOut << ", Duration: " << time << std::endl;
    }
}

void Logger::logServerAllocated(int serverIndex) {
    if (logFile.is_open()) {
        logFile << "Server Allocated - Index: " << serverIndex << std::endl;
    }
}

void Logger::logServerDeallocated(int serverIndex) {
    if (logFile.is_open()) {
        logFile << "Server Deallocated - Index: " << serverIndex << std::endl;
    }
}

void Logger::logFinalState(const std::vector<bool>& serverStatus, int queueSize) {
    if (logFile.is_open()) {
        logFile << "Final State - Queue Size: " << queueSize << ", Server Status: ";
        for (bool status : serverStatus) {
            logFile << (status ? "1" : "0");
        }
        logFile << std::endl;
    }
}