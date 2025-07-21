#include "RequestQueue.h"
#include "Request.h"

/**
 * @brief Fills the request queue with a specified number of randomly generated requests.
 * 
 * @param numReqs The number of requests to generate and add to the queue.
 */
void RequestQueue::fillQueue(int numReqs) {
    for (int i = 0; i < numReqs; ++i) {
        Request req = Request::genRandomRequest();
        queue.push(req);
    }
}

/**
 * @brief Removes and returns the front request from the queue.
 * 
 * @return The oldest Request object in the queue.
 */
Request RequestQueue::popRequest() {
    Request front = queue.front();
    queue.pop();
    return front;
}
