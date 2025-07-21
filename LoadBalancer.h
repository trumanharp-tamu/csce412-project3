#pragma once

#include "WebServer.h"
#include "RequestQueue.h"
#include <vector>
#include "Logger.h"

using std::vector;

/**
 * @class LoadBalancer
 * @brief Simulates a dynamic load balancer managing a pool of web servers and processing requests.
 */
class LoadBalancer {
    int numServers;                      ///< Initial number of web servers.
    int totalCycles;                     ///< Total number of simulation cycles.
    int cyclesLeft;                      ///< Number of cycles remaining in the simulation.
    int percentChanceGenerateRequest;    ///< Chance (0–100) of generating a new request each cycle.

    int nextServerId = 0;                ///< ID tracker for server allocation (unused here but reserved for extensions).

    vector<WebServer> servers;           ///< Vector containing the active web servers.
    RequestQueue requestQueue;           ///< Queue of incoming requests to be processed.
    Logger logger;                       ///< Logger instance for recording simulation activity.

public:
    /**
     * @brief Constructs a LoadBalancer instance.
     * @param servers Initial number of web servers.
     * @param totalCycles Total number of simulation cycles.
     * @param percentChanceGenerateRequest Chance (0–100) to generate a request each cycle.
     * @param verboseLogging Enables detailed logging if true.
     */
    LoadBalancer(int servers, int totalCycles, int percentChanceGenerateRequest, bool verboseLogging = false);

    /**
     * @brief Executes a single simulation cycle, handling server activity and request dispatch.
     */
    void runCycle();

    /**
     * @brief Runs the entire simulation for the configured number of cycles.
     */
    void run();
};
