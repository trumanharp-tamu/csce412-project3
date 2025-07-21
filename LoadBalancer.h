#pragma once

#include "WebServer.h"
#include "RequestQueue.h"
#include <vector>
#include "Logger.h"

using std::vector;

class LoadBalancer {
    int numServers;
    int totalCycles;
    int cyclesLeft;
    int percentChanceGenerateRequest;

    int nextServerId = 0;
    

    vector<WebServer> servers;
    RequestQueue requestQueue;
    Logger logger;
    

public:
    LoadBalancer(int servers, int totalCycles, int percentChanceGenerateRequest, bool verboseLogging = false);
    void runCycle();
    void run();
};