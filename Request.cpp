#include "Request.h"

string Request::genRandomIp() {
    int part1 = rand() % 256;
    int part2 = rand() % 256;
    int part3 = rand() % 256;
    int part4 = rand() % 256;
    return std::to_string(part1) + "." + std::to_string(part2) + "." + std::to_string(part3) + "." + std::to_string(part4);
}

int Request::genRandomProcessingTime() {
    return MIN_TASK_TIME + rand() % (MAX_TASK_TIME - MIN_TASK_TIME + 1);
}