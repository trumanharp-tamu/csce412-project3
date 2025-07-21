#pragma once
#include <fstream>
#include <vector>
#include <string>

/**
 * @class Logger
 * @brief Handles logging for the load balancer simulation, including server activity and request processing.
 */
class Logger {
    std::ofstream logFile;         ///< Output stream for writing logs to a file.
    int minTaskTime;               ///< Minimum allowed task processing time.
    int maxTaskTime;               ///< Maximum allowed task processing time.
    int maxIpPart;                 ///< Maximum value for an IP address segment (0–maxIpPart).
    int startingQueueSize = 0;     ///< Size of the request queue at the start of the simulation.
    int endingQueueSize = 0;       ///< Size of the request queue at the end of the simulation.
    int requestCount = 0;          ///< Total number of requests generated.
    int assignedRequests = 0;      ///< Total number of requests assigned to servers.
    bool verbose = false;          ///< Enables detailed logging if true.

public:
    /**
     * @brief Constructs a Logger object and opens the log file.
     * @param filename Name of the log file to write to.
     * @param minTaskTime Minimum processing time for a request.
     * @param maxTaskTime Maximum processing time for a request.
     * @param maxIpPart Maximum value for a segment of an IP address.
     * @param verbose Enables detailed logging if true.
     */
    Logger(const std::string& filename, int minTaskTime, int maxTaskTime, int maxIpPart, bool verbose);

    /**
     * @brief Destructor. Closes the log file if it's open.
     */
    ~Logger();

    /**
     * @brief Sets the initial size of the request queue and logs it.
     * @param size Size of the queue at the start.
     */
    void setStartingQueueSize(int size);

    /**
     * @brief Logs startup configuration and simulation parameters.
     * @param numServers Initial number of servers.
     * @param totalCycles Total simulation cycles to run.
     * @param percentChanceGenerateRequest Probability (0–100) of generating a request per cycle.
     */
    void logStartup(int numServers, int totalCycles, int percentChanceGenerateRequest);

    /**
     * @brief Sets the final size of the request queue and logs it.
     * @param size Size of the queue at the end.
     */
    void setEndingQueueSize(int size);

    /**
     * @brief Logs the state of the system at the given cycle.
     * @param cycle Current cycle number.
     * @param queueSize Number of pending requests in the queue.
     */
    void logCycle(int cycle, int queueSize);

    /**
     * @brief Logs when a request is assigned to a server.
     * @param serverId ID of the server receiving the request.
     * @param ipIn Source IP address of the request.
     * @param ipOut Destination IP address of the request.
     * @param time Processing time of the request.
     */
    void logAssignedRequest(int serverId, const std::string& ipIn, const std::string& ipOut, int time);

    /**
     * @brief Logs when a new request is generated.
     * @param ipIn Source IP address of the request.
     * @param ipOut Destination IP address of the request.
     * @param time Processing time of the request.
     */
    void logGeneratedRequest(const std::string& ipIn, const std::string& ipOut, int time);

    /**
     * @brief Logs when a server is dynamically allocated.
     * @param serverIndex Index of the newly added server.
     */
    void logServerAllocated(int serverIndex);

    /**
     * @brief Logs when a server is dynamically deallocated.
     * @param serverIndex Index after deallocation (new server count).
     */
    void logServerDeallocated(int serverIndex);

    /**
     * @brief Logs the final state of all servers and remaining queue size after simulation ends.
     * @param serverStatus Boolean vector indicating whether each server is busy.
     * @param queueSize Remaining number of requests in the queue.
     */
    void logFinalState(const std::vector<bool>& serverStatus, int queueSize);
};
