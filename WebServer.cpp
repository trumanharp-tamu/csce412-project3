#include "WebServer.h"

/**
 * @brief Assigns a request to the server and sets it to busy.
 * 
 * Initializes the server's internal request and sets the processing time based on the request.
 * 
 * @param req The request to be processed by the server.
 */
void WebServer::giveRequest(const Request& req) {
    request = req;
    timeLeft = req.processingTime;
    busy = true;
}

/**
 * @brief Processes a single simulation cycle.
 * 
 * Decrements the remaining processing time. If the request is complete,
 * marks the server as no longer busy.
 */
void WebServer::processCycle() {
    if (busy) {
        timeLeft--;
        if (timeLeft <= 0) {
            busy = false;
        }
    }
}
