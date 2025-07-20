#include "RequestQueue.h"
#include "Request.h"

void RequestQueue::fillQueue(int numReqs) {
    for (int i = 0; i < numReqs; ++i) {
        Request req(
            Request::genRandomIp(),
            Request::genRandomIp(),
            Request::genRandomProcessingTime()
        );
        queue.push(req);
    }
}