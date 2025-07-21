#pragma once

#include "Request.h"
#include <queue>

class RequestQueue {
    std::queue<Request> queue;
public:
    RequestQueue() : queue() {}
    void fillQueue(int numReqs);
    Request& popRequest(); 

    void addRequest (Request& req) { queue.push(req); }
    void clear() { while (!queue.empty()) queue.pop(); }
    bool empty() { return queue.empty(); }
    int size() { return queue.size(); }

};