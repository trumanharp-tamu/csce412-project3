#include "RequestQueue.h"
#include "Request.h"

void RequestQueue::fillQueue(int numReqs) {
    for (int i = 0; i < numReqs; ++i) {
        Request req = Request::genRandomRequest();
        queue.push(req);
    }
}

Request RequestQueue::popRequest() {
    Request front = queue.front();
    queue.pop();
    return front;
}