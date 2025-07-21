#include "WebServer.h"


void WebServer::giveRequest(const Request& req) {
    request = req;
    timeLeft = req.processingTime;
    busy = true;
}

void WebServer::processCycle() {
    if (busy) {
        timeLeft--;
        if (timeLeft <= 0) {
            busy = false;
        }
    }
}