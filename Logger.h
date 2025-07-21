#pragma once
#include <fstream>
#include <vector>
#include <string>

class Logger {
    std::ofstream logFile;
    int minTaskTime, maxTaskTime, maxIpPart;
    int startingQueueSize = 0;
    int endingQueueSize = 0;
    int requestCount = 0;
    int assignedRequests = 0;
    bool verbose = false;
public:
    Logger(const std::string& filename, int minTaskTime, int maxTaskTime, int maxIpPart, bool verbose);
    ~Logger();

    void setStartingQueueSize(int size);
    void logStartup(int numServers, int totalCycles, int percentChanceGenerateRequest);
    void setEndingQueueSize(int size);
    void logCycle(int cycle, int queueSize);
    void logAssignedRequest(int serverId, const std::string& ipIn, const std::string& ipOut, int time);
    void logGeneratedRequest(const std::string& ipIn, const std::string& ipOut, int time);
    void logServerAllocated(int serverIndex);
    void logServerDeallocated(int serverIndex);
    void logFinalState(const std::vector<bool>& serverStatus, int queueSize);


};