#include "WebServer.h"
#include "RequestQueue.h"
#include <vector>

using std::vector;

class LoadBalancer {
    int numServers;
    int totalCycles;
    int cyclesLeft;
    int percentChanceGenerateRequest;

    vector<WebServer> servers;
    RequestQueue requestQueue;

public:
    LoadBalancer(int servers, int totalCycles, int percentChanceGenerateRequest);
    void runCycle();
    void run();
};