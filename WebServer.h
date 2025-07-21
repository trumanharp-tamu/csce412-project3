#pragma once

#include "Request.h"

/**
 * @class WebServer
 * @brief Simulates a server that processes a single request at a time over multiple cycles.
 */
class WebServer {
    Request request;    ///< The current request being processed by the server.
    int timeLeft;       ///< Time remaining to complete the current request.
    bool busy;          ///< Indicates whether the server is currently processing a request.

public:
    /**
     * @brief Constructs an idle WebServer with no request and zero processing time.
     */
    WebServer() : timeLeft(0), busy(false) {}

    /**
     * @brief Assigns a new request to the server and marks it as busy.
     * @param req The request to assign.
     */
    void giveRequest(const Request& req);

    /**
     * @brief Processes one simulation cycle. Decreases timeLeft and marks server idle if complete.
     */
    void processCycle();

    /**
     * @brief Checks if the server is currently busy.
     * @return True if the server is processing a request, false otherwise.
     */
    bool isBusy() const { return busy; }
};
