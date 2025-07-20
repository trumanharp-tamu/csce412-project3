#include <string>

using std::string;

const int MIN_TASK_TIME = 1;
const int MAX_TASK_TIME = 50;

struct Request {
    string ipIn;
    string ipOut;
    int processingTime;

    Request() : ipIn("0.0.0.0"), ipOut("0.0.0.0"), processingTime(0) {}
    Request(const string& in, const string& out, int time) : ipIn(in), ipOut(out), processingTime(time) {}

    string genRandomIp();
    int genRandomProcessingTime();
};