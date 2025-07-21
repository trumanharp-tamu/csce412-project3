#pragma once

#include <string>

using std::string;

const int MIN_TASK_TIME = 1;      ///< Minimum allowed processing time for a request.
const int MAX_TASK_TIME = 50;     ///< Maximum allowed processing time for a request.
const int MAX_IP_PART = 255;      ///< Maximum value for an individual IP address segment.

/**
 * @struct Request
 * @brief Represents a network request with input/output IPs and a processing time.
 */
struct Request {
    string ipIn;           ///< Source IP address.
    string ipOut;          ///< Destination IP address.
    int processingTime;    ///< Time required to process the request.

    /**
     * @brief Default constructor initializing with placeholder IPs and 0 processing time.
     */
    Request() : ipIn("0.0.0.0"), ipOut("0.0.0.0"), processingTime(0) {}

    /**
     * @brief Parameterized constructor to initialize a request.
     * @param in Source IP address.
     * @param out Destination IP address.
     * @param time Processing time.
     */
    Request(const string& in, const string& out, int time) : ipIn(in), ipOut(out), processingTime(time) {}

    /**
     * @brief Generates a random IP address in the format "X.X.X.X".
     * @return A valid randomly generated IP address.
     */
    static string genRandomIp();

    /**
     * @brief Generates a random processing time within allowed bounds.
     * @return An integer between MIN_TASK_TIME and MAX_TASK_TIME.
     */
    static int genRandomProcessingTime();

    /**
     * @brief Generates a random request with random IPs and processing time.
     * @return A fully populated Request object.
     */
    static Request genRandomRequest();
};
