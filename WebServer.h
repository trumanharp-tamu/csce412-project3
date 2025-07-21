#pragma once

#include "Request.h"

class WebServer {
    Request request;
    int timeLeft;
    bool busy;

public:
    WebServer() : timeLeft(0), busy(false) {};
    

    void giveRequest(const Request& req);
    void processCycle();
    bool isBusy() const { return busy; };
};