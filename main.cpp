#include <cstdio>
#include <ctime>
#include "LoadBalancer.h"

/**
 * @brief Entry point for the Load Balancer simulation.
 * 
 * Prompts the user for simulation parameters:
 * - Number of initial servers
 * - Total simulation cycles
 * - Percent chance of request generation per cycle
 * - Verbose logging option
 * 
 * Initializes the random seed, constructs a LoadBalancer instance,
 * and runs the simulation.
 * 
 * @return Exit status (0 on success).
 */
int main() {
    srand(time(0));

    int numServers, totalCycles, percentRequestGeneration, verboseInt;
    bool verboseLogging;

    printf("Enter number of servers: ");
    scanf("%d", &numServers);

    printf("Enter total number of cycles: ");
    scanf("%d", &totalCycles);

    printf("Enter percent chance of generating a request each cycle: ");
    scanf("%d", &percentRequestGeneration);

    printf("Enter 1 for verbose logging, 0 for normal logging: ");
    scanf("%d", &verboseInt);

    verboseLogging = (verboseInt == 1);
    
    LoadBalancer loadBalancer(numServers, totalCycles, percentRequestGeneration, verboseLogging);
    loadBalancer.run();

    return 0;
}
