#include "LoadBalancer.h"
#include <algorithm>
#include <random>

LoadBalancer::LoadBalancer(int numServers, int totalCycles, int percent, bool verboseLogging) 
    : numServers(numServers), totalCycles(totalCycles), cyclesLeft(totalCycles), percentChanceGenerateRequest(percent), servers(numServers), logger("load_balancer.log", MIN_TASK_TIME, MAX_TASK_TIME, MAX_IP_PART, verboseLogging) {
    requestQueue.fillQueue(numServers * 100);
    logger.setStartingQueueSize(numServers * 100);
    logger.logStartup(numServers, totalCycles, percent);
    //TODO log randomness for ip and processing time generation
    //TODO log randomess for request generation
}

void  LoadBalancer::run() {
    while (cyclesLeft > 0) {
        runCycle();
        cyclesLeft--;
    }

    std::vector<bool> serverStatus;
    for (const WebServer& server : servers) {
        serverStatus.push_back(server.isBusy());
    }

    logger.logFinalState(serverStatus, requestQueue.size());
}

void LoadBalancer::runCycle() {
    logger.logCycle(totalCycles - cyclesLeft, requestQueue.size());
    bool tryDeallocate = false;

    if (requestQueue.size() > servers.size() * 100) {
        servers.push_back(WebServer());
        logger.logServerAllocated(servers.size() - 1);
    } else if (requestQueue.size() < servers.size() * 50 && servers.size() > 1) {
        tryDeallocate = true;
    }


    vector<WebServer*> readyServers;
    for (auto it = servers.begin(); it!= servers.end();) {
        it->processCycle();
        if (!it->isBusy()) {
            if (tryDeallocate) {
                it = servers.erase(it);
                tryDeallocate = false;
                logger.logServerDeallocated(servers.size());
                continue;
                
            }
            readyServers.push_back(&(*it));
        }
        it++;
    }

    // Shuffles the idle servers to distribute requests randomly
    std::shuffle(readyServers.begin(), readyServers.end(), std::default_random_engine());
    for (WebServer* server : readyServers) {
        int index = std::distance(servers.begin(), std::find_if(servers.begin(), servers.end(), [server](const WebServer& s) { return &s == server; }));
        
        if (!requestQueue.empty()) {
            Request req = requestQueue.popRequest();
            server->giveRequest(req);
            logger.logAssignedRequest(index, req.ipIn, req.ipOut, req.processingTime);
        }
    }

    if ((rand() % 100) < percentChanceGenerateRequest) {
        Request newRequest = Request::genRandomRequest();
        requestQueue.addRequest(newRequest);
        logger.logGeneratedRequest(newRequest.ipIn, newRequest.ipOut, newRequest.processingTime);
    }

    
}

