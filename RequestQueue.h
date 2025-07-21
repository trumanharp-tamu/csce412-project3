#pragma once

#include "Request.h"
#include <queue>

/**
 * @class RequestQueue
 * @brief Manages a queue of Request objects to simulate incoming network traffic.
 */
class RequestQueue {
    std::queue<Request> queue;  ///< Underlying queue storing Request objects.

public:
    /**
     * @brief Default constructor for RequestQueue.
     */
    RequestQueue() : queue() {}

    /**
     * @brief Fills the queue with a specified number of random requests.
     * @param numReqs Number of requests to generate and add to the queue.
     */
    void fillQueue(int numReqs);

    /**
     * @brief Removes and returns the request at the front of the queue.
     * @return The oldest Request in the queue.
     */
    Request popRequest();

    /**
     * @brief Adds a request to the back of the queue.
     * @param req The Request object to add.
     */
    void addRequest(const Request& req) { queue.push(req); }

    /**
     * @brief Clears all requests from the queue.
     */
    void clear() { while (!queue.empty()) queue.pop(); }

    /**
     * @brief Checks if the queue is empty.
     * @return True if the queue has no requests, false otherwise.
     */
    bool empty() { return queue.empty(); }

    /**
     * @brief Returns the number of requests in the queue.
     * @return The current size of the queue.
     */
    int size() { return queue.size(); }
};
