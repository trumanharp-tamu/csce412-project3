#pragma once

#include <string>

using std::string;

const int MIN_TASK_TIME = 1;
const int MAX_TASK_TIME = 50;
const int MAX_IP_PART = 255;

struct Request {
    string ipIn;
    string ipOut;
    int processingTime;

    Request() : ipIn("0.0.0.0"), ipOut("0.0.0.0"), processingTime(0) {}
    Request(const string& in, const string& out, int time) : ipIn(in), ipOut(out), processingTime(time) {}

    static string genRandomIp();
    static int genRandomProcessingTime();
    static Request genRandomRequest();
};