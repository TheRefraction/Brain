#include <stdio.h>

#include "network.h"

int main(int argc, const char* argv[]) {
    printf("Hello World\n");

    // TODO: Clear up code
    // TODO: Main loop acquisition
    // TODO: Check for memory allocation/cleanup
    List *inputs = NULL;
    inputs = insertTailList(inputs, 1);
    inputs = insertTailList(inputs, 0);
    inputs = insertTailList(inputs, 1);

    List *numOfNeurons = NULL;
    numOfNeurons = insertTailList(numOfNeurons, 2);
    numOfNeurons = insertTailList(numOfNeurons, 1);

    Network *network = allocateNetwork(2, numOfNeurons, 3);

    inputs = getNetworkOutputs(network, inputs);
    printList(inputs, 1);

    freeNetwork(network);
    freeList(numOfNeurons);
    freeList(inputs);

    return 0;
}
