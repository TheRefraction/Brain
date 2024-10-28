#ifndef NEURON_H
#define NEURON_H

#include "list.h"

typedef struct {
    List *weights;
    float threshold;
} Neuron;

Neuron *allocateNeuron(List *weights, float threshold);
void freeNeuron(Neuron *neuron);
float getNeuronOutput(Neuron *neuron, List *inputs);

void printNeuron(Neuron *neuron);

/*.*/ // I am Lorna
#endif //NEURON_H
