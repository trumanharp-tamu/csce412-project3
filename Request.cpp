#include "Request.h"

/**
 * @brief Generates a random IP address in the format "X.X.X.X".
 * 
 * Each segment (X) is a random integer between 1 and MAX_IP_PART (inclusive).
 * 
 * @return A randomly generated IPv4 address as a string.
 */
string Request::genRandomIp() {
    int part1 = rand() % MAX_IP_PART + 1;
    int part2 = rand() % MAX_IP_PART + 1;
    int part3 = rand() % MAX_IP_PART + 1;
    int part4 = rand() % MAX_IP_PART + 1;
    return std::to_string(part1) + "." + std::to_string(part2) + "." + std::to_string(part3) + "." + std::to_string(part4);
}

/**
 * @brief Generates a random processing time within the allowed task time range.
 * 
 * @return An integer between MIN_TASK_TIME and MAX_TASK_TIME (inclusive).
 */
int Request::genRandomProcessingTime() {
    return MIN_TASK_TIME + rand() % (MAX_TASK_TIME - MIN_TASK_TIME + 1);
}

/**
 * @brief Generates a Request object with random IP addresses and processing time.
 * 
 * @return A randomly generated Request instance.
 */
Request Request::genRandomRequest() {
    return Request(genRandomIp(), genRandomIp(), genRandomProcessingTime());
}
