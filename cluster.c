#include "cluster.h"

#include <stdio.h>
#include <stdlib.h>

ClusterNode *allocateClusterNode(Neuron *neuron) {
    ClusterNode *node = malloc(sizeof(ClusterNode));
    node->neuron = neuron;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void freeClusterNode(ClusterNode *node) {
    if(node != NULL)
    {
        freeNeuron(node->neuron);
        free(node);
    }
}

Cluster *allocateCluster(unsigned int numOfNeurons, unsigned int numOfInputs) {
    if(numOfNeurons == 0 || numOfInputs == 0)
    {
        return NULL;
    }

    Cluster *cluster = malloc(sizeof(Cluster));
    cluster->head = NULL;
    cluster->tail = NULL;
    cluster->length = 0;

    for (unsigned int i = 0; i < numOfNeurons; i++) {
        printf("Acquisition of weights for Neuron %d\n", i + 1);

        List *weights = NULL;
        for (unsigned int j = 0; j < numOfInputs; j++) {
            float w;
            printf("Enter weight %d:", j + 1);
            scanf("%f", &w);
            weights = insertTailList(weights, w);
        }
        float t;
        printf("Enter threshold for Neuron %d:", i + 1);
        scanf("%f", &t);
        Neuron *neuron = allocateNeuron(weights, t);

        cluster = insertHeadCluster(cluster, neuron);

        printf("------------------\n");
    }

    return cluster;
}

void freeCluster(Cluster *cluster)
{
    if(cluster != NULL)
    {
        while(cluster->length > 0) {
            cluster = removeHeadCluster(cluster);
        }
        free(cluster);
    }
}

Cluster *insertHeadCluster(Cluster *cluster, Neuron *neuron) {
    if(cluster == NULL) {
        return NULL;
    }
    ClusterNode *newNode = allocateClusterNode(neuron);
    newNode->next = cluster->head;
    if(cluster->head != NULL) {
        cluster->head->prev = newNode;
    } else {
        cluster->tail = newNode;
    }
    cluster->head = newNode;
    cluster->length++;

    return cluster;
}

Cluster *insertTailCluster(Cluster *cluster, Neuron *neuron) {
    if(cluster == NULL) {
        return NULL;
    }
    ClusterNode *newNode = allocateClusterNode(neuron);
    newNode->prev = cluster->tail;
    if(cluster->tail != NULL) {
        cluster->tail->next = newNode;
    } else {
        cluster->head = newNode;
    }
    cluster->tail = newNode;
    cluster->length++;

    return cluster;
}

Cluster *removeHeadCluster(Cluster *cluster) {
    if(cluster == NULL || cluster->length == 0) {
        return NULL;
    }

    ClusterNode *tmp = cluster->head;
    cluster->head = tmp->next;
    if(cluster->head != NULL) {
        cluster->head->prev = NULL;
    } else {
        cluster->tail = NULL;
    }
    freeClusterNode(tmp);
    cluster->length--;

    return cluster;
}

Cluster *removeTailCluster(Cluster *cluster) {
    if(cluster == NULL || cluster->length == 0) {
        return NULL;
    }

    ClusterNode *tmp = cluster->tail;
    cluster->tail = tmp->prev;
    if(cluster->tail != NULL) {
        cluster->tail->next = NULL;
    } else {
        cluster->head = NULL;
    }
    freeClusterNode(tmp);
    cluster->length--;

    return cluster;
}

List *getClusterOutput(Cluster *cluster, List *inputs)
{
    if(cluster == NULL || cluster->length == 0 || inputs == NULL || inputs->length == 0)
    {
        return NULL;
    }

    List *outputs = createList(cluster->length, 0);
    const ClusterNode *It = cluster->head;
    Node *node = outputs->head;
    while(It != NULL)
    {
        node->value = getNeuronOutput(It->neuron, inputs);

        node = node->next;
        It = It->next;
    }

    return outputs;
}