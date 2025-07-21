#include <cstdio>
#include <ctime>
#include "LoadBalancer.h"


int main() {
    srand(time(0));

    int numServers, totalCycles, percentRequestGeneration;
    printf("Enter number of servers: ");
    scanf("%d", &numServers);
    printf("Enter total number of cycles: ");
    scanf("%d", &totalCycles);
    printf("Enter percent chance of generating a request each cycle: ");
    scanf("%d", &percentRequestGeneration);

    LoadBalancer loadBalancer(numServers, totalCycles, percentRequestGeneration);
    loadBalancer.run();

    return 0;
}