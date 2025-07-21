#include "LoadBalancer.h"

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
    //todo main logic for a cycle
}

