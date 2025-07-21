#include "Logger.h"
#include <iostream>

/**
 * @brief Constructs a Logger object, initializes internal parameters, and opens the log file.
 * 
 * @param filename Name of the log file to be created.
 * @param minTaskTime Minimum allowed processing time for a request.
 * @param maxTaskTime Maximum allowed processing time for a request.
 * @param maxIpPart Maximum value for a segment of an IP address.
 * @param verbose If true, enables detailed per-cycle and per-request logging.
 */
Logger::Logger(const std::string& filename, int minTaskTime, int maxTaskTime, int maxIpPart, bool verbose)
    : minTaskTime(minTaskTime), maxTaskTime(maxTaskTime), maxIpPart(maxIpPart), verbose(verbose) {
    logFile.open(filename);
    if (!logFile.is_open()) {
        printf("Error opening log file: %s\n", filename.c_str());
    }
    logFile << "Initialized Load Balancer." << std::endl;
    logFile << "Logger initialized with file: " << filename << std::endl;
}

/**
 * @brief Destructor that closes the log file if it's still open.
 */
Logger::~Logger() {
    if (logFile.is_open()) {
        logFile.close();
    }
}

/**
 * @brief Logs simulation startup parameters and configuration.
 * 
 * @param numServers Number of servers at startup.
 * @param totalCycles Total number of cycles to simulate.
 * @param percentChanceGenerateRequest Probability of generating a new request each cycle.
 */
void Logger::logStartup(int numServers, int totalCycles, int percentChanceGenerateRequest) {
    if (logFile.is_open()) {
        logFile << "Startup Parameters:" << std::endl;
        logFile << "Number of servers: " << numServers << std::endl;
        logFile << "Total cycles: " << totalCycles << std::endl;
        logFile << "Percent chance of generating a request each cycle: " << percentChanceGenerateRequest << "%" << std::endl;
        logFile << "Min Task Time: " << minTaskTime << ", Max Task Time: " << maxTaskTime
                << ", IP Segment Range: 0-" << maxIpPart << std::endl;
    } else {
        std::cerr << "Error: Log file is not open." << std::endl;
    }
}

/**
 * @brief Logs the initial size of the request queue.
 * 
 * @param size Number of requests in the queue at the start.
 */
void Logger::setStartingQueueSize(int size) {
    startingQueueSize = size;
    if (logFile.is_open()) {
        logFile << "Starting queue size: " << size << std::endl;
    }
}

/**
 * @brief Logs the final size of the request queue.
 * 
 * @param size Number of requests in the queue at the end.
 */
void Logger::setEndingQueueSize(int size) {
    endingQueueSize = size;
    if (logFile.is_open()) {
        logFile << "Ending queue size: " << size << std::endl;
    }
}

/**
 * @brief Logs current simulation cycle and queue size (if verbose is enabled).
 * 
 * @param cycle Current simulation cycle.
 * @param queueSize Number of requests currently in the queue.
 */
void Logger::logCycle(int cycle, int queueSize) {
    if (logFile.is_open() && verbose) {
        logFile << "Cycle: " << cycle << ", Queue Size: " << queueSize << std::endl;
    }
}

/**
 * @brief Logs when a request is assigned to a server (if verbose is enabled).
 * 
 * @param serverId ID of the server assigned.
 * @param ipIn Source IP address of the request.
 * @param ipOut Destination IP address of the request.
 * @param time Processing time of the request.
 */
void Logger::logAssignedRequest(int serverId, const std::string& ipIn, const std::string& ipOut, int time) {
    if (logFile.is_open() && verbose) {
        logFile << "  Assigned Request - Server ID: " << serverId
                << ", IP In: " << ipIn
                << ", IP Out: " << ipOut
                << ", Duration: " << time << std::endl;
    }
}

/**
 * @brief Logs when a new request is generated (if verbose is enabled).
 * 
 * @param ipIn Source IP address of the request.
 * @param ipOut Destination IP address of the request.
 * @param time Processing time of the request.
 */
void Logger::logGeneratedRequest(const std::string& ipIn, const std::string& ipOut, int time) {
    if (logFile.is_open() && verbose) {
        logFile << "  Generated Request - IP In: " << ipIn
                << ", IP Out: " << ipOut
                << ", Duration: " << time << std::endl;
    }
}

/**
 * @brief Logs the allocation of a new server.
 * 
 * @param serverIndex Index of the newly added server.
 */
void Logger::logServerAllocated(int serverIndex) {
    if (logFile.is_open()) {
        logFile << "--- Server Allocated - Index: " << serverIndex << " ---" << std::endl;
    }
}

/**
 * @brief Logs the deallocation of a server.
 * 
 * @param serverIndex Current number of servers after deallocation.
 */
void Logger::logServerDeallocated(int serverIndex) {
    if (logFile.is_open()) {
        logFile << "--- Server Deallocated - Index: " << serverIndex << " ---" << std::endl;
    }
}

/**
 * @brief Logs the final simulation state, including each server's status and remaining queue size.
 * 
 * @param serverStatus A vector indicating whether each server is busy (`true`) or idle (`false`).
 * @param queueSize Number of requests left in the queue.
 */
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
    }
}
