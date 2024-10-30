#ifndef NEURON_H
#define NEURON_H

#include "list.h"

/** definition of a new structure "Neuron" with a weight and a threshold
 *
 */
typedef struct {
    List *weights;
    float threshold;
} Neuron;

/**
 * allocate memory for a new neuron
 * @param weights
 * @param threshold
 * @return
 */
Neuron *allocateNeuron(List *weights, float threshold);

/**
 * free the memory of a neuron
 * @param neuron
 */
void freeNeuron(Neuron *neuron);

/**
 * get the Neuron Output with the sum of Ei*Wi
 * @param neuron
 * @param inputs
 * @return
 */
float getNeuronOutput(const Neuron *neuron, const List *inputs);

/**
 * Print the weight and the threshold of a specific neuron
 * @param neuron
 */
void printNeuron(Neuron *neuron);

/*.*/ // I am Lorna
#endif //NEURON_H
