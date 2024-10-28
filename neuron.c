#include "neuron.h"

#include <stdio.h>
#include <stdlib.h>

Neuron *allocateNeuron(List *weights, float threshold) {
    Neuron *neuron = malloc(sizeof(Neuron));
    neuron->weights = weights;
    neuron->threshold = threshold;

    return neuron;
}

void freeNeuron(Neuron *neuron) {
    freeList(neuron->weights);
    free(neuron);
}

float getNeuronOutput(Neuron *neuron, List *inputs) {
    if(neuron == NULL || neuron->weights == NULL || inputs == NULL || inputs->length != neuron->weights->length) {
        printf("Could not get output!\n");
        return 0;
    }
    float x = 0;
    Node *Wi = neuron->weights->head;
    Node *Ei = inputs->head;
    while(Wi != NULL) {
        x += Wi->value * Ei->value;
        Wi = Wi->next;
        Ei = Ei->next;
    }

    return x >= neuron->threshold;
}

void printNeuron(Neuron *neuron) {
    if(neuron == NULL) {
        printf("Neuron is undefined\n");
        return;
    }
    printf("Neuron<%p>: Weights->", neuron);
    printList(neuron->weights, 0);
    printf(", Threshold->%f\n", neuron->threshold);
}

/*I feel a bit useless ( :'), I write only little commentaries, */

