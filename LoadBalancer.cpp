#include "LoadBalancer.h"
#include <algorithm>
#include <random>

LoadBalancer::LoadBalancer(int numServers, int totalCycles, int percentChanceGenerateRequest) 
    : numServers(numServers), totalCycles(totalCycles), cyclesLeft(totalCycles), percentChanceGenerateRequest(percentChanceGenerateRequest), servers(numServers) {

    requestQueue.fillQueue(numServers * 100);
    //TODO Log starter queue size
    //TODO log randomness for ip and processing time generation
    //TODO log randomess for request generation
}

void  LoadBalancer::run() {
    while (cyclesLeft > 0) {
        runCycle();
        cyclesLeft--;
    }
    //TODO Log final state of servers and request queue
}

void LoadBalancer::runCycle() {
    bool tryDeallocate = false;
    
    if (requestQueue.size() > numServers * 100) {
        servers.push_back(WebServer());
        //TODO Log server allocation
    } else if (requestQueue.size() < numServers * 50 && servers.size() > 1) {
        tryDeallocate = true;
    }


    vector<WebServer*> readyServers;
    for (auto it = servers.begin(); it!= servers.end();) {
        it->processCycle();
        if (!it->isBusy()) {
            if (tryDeallocate) {
                it = servers.erase(it);
                tryDeallocate = false;
                continue;
                //TODO Log server deallocation
            }
            readyServers.push_back(&(*it));
        }
        it++;
    }

    // Shuffles the idle servers to distribute requests randomly
    std::shuffle(readyServers.begin(), readyServers.end(), std::default_random_engine());
    for (WebServer* server : readyServers) {
        if (!requestQueue.empty()) {
            Request req = requestQueue.popRequest();
            server->giveRequest(req);
            //TODO Log request assignment
        }
    }

    if ((rand() % 100) < percentChanceGenerateRequest) {
        Request newRequest = Request::genRandomRequest();
        requestQueue.addRequest(newRequest);
        //TODO Log new request generation
    }

    
}

