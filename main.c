#include <stdio.h>

#include "neuron.h"

int main(int argc, const char* argv[]) {
    List *weights = insertHeadList(NULL, 2);
    weights = insertHeadList(weights, 4);
    weights = insertHeadList(weights, 6);
    weights = insertHeadList(weights, 8);

    Neuron *neuron = allocateNeuron(weights, 300);

    printNeuron(neuron);

    List *inputs = insertHeadList(NULL, 0.67);
    inputs = insertHeadList(inputs, 1.42);
    inputs = insertHeadList(inputs, 0);
    inputs = insertHeadList(inputs, 0.1);

    printf("Result: %f\n", getNeuronOutput(neuron, inputs));

    freeNeuron(neuron);
    neuron = NULL;

    return 0;
}



/*Priere de ne pas enlever mes seules traces d'existences sur ce projet*/