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

    vector<WebServer> servers;
    RequestQueue requestQueue;
    Logger logger;

public:
    LoadBalancer(int servers, int totalCycles, int percentChanceGenerateRequest);
    void runCycle();
    void run();
};