#include "network.h"

#include <stdio.h>
#include <stdlib.h>

NetworkNode *allocateNetworkNode(Cluster *cluster)
{
    NetworkNode *node = malloc(sizeof(NetworkNode));
    node->cluster = cluster;
    node->next = NULL;
    node->prev = NULL;

    return node;
}

void freeNetworkNode(NetworkNode *node)
{
    if (node != NULL)
    {
        freeCluster(node->cluster);
        free(node);
    }
}

Network *allocateNetwork(unsigned int numOfClusters, List *numOfNeurons, unsigned int numOfInputs)
{
    if(numOfNeurons == NULL || numOfClusters == 0 || numOfNeurons->length != numOfClusters)
    {
        return NULL;
    }

    Network *network = malloc(sizeof(Network));
    network->head = NULL;
    network->tail = NULL;
    network->length = 0;
    network->numOfInputs = numOfInputs;

    unsigned int inputs = numOfInputs;

    Node *It = numOfNeurons->head;
    while(It != NULL)
    {
        printf("Now allocating Cluster %d\n------------------\n", network->length + 1);
        Cluster *cluster = allocateCluster(It->value, inputs);
        network = insertTailNetwork(network, cluster);

        inputs = It->value;

        It = It->next;
    }

    return network;
}

void freeNetwork(Network *network)
{
    if(network != NULL)
    {
        while(network->length > 0) {
            network = removeHeadNetwork(network);
        }
        free(network);
    }
}

Network *insertHeadNetwork(Network *network, Cluster *cluster) {
    if(network == NULL) {
        return NULL;
    }
    NetworkNode *newNode = allocateNetworkNode(cluster);
    newNode->next = network->head;
    if(network->head != NULL) {
        network->head->prev = newNode;
    } else {
        network->tail = newNode;
    }
    network->head = newNode;
    network->length++;

    return network;
}

Network *insertTailNetwork(Network *network, Cluster *cluster) {
    if(network == NULL) {
        return NULL;
    }
    NetworkNode *newNode = allocateNetworkNode(cluster);
    newNode->prev = network->tail;
    if(network->tail != NULL) {
        network->tail->next = newNode;
    } else {
        network->head = newNode;
    }
    network->tail = newNode;
    network->length++;

    return network;
}

Network *removeHeadNetwork(Network *network) {
    if(network == NULL || network->length == 0) {
        return NULL;
    }

    NetworkNode *tmp = network->head;
    network->head = tmp->next;
    if(network->head != NULL) {
        network->head->prev = NULL;
    } else {
        network->tail = NULL;
    }
    freeNetworkNode(tmp);
    network->length--;

    return network;
}

Network *removeTailNetwork(Network *network) {
    if(network == NULL || network->length == 0) {
        return NULL;
    }

    NetworkNode *tmp = network->tail;
    network->tail = tmp->prev;
    if(network->tail != NULL) {
        network->tail->next = NULL;
    } else {
        network->head = NULL;
    }
    freeNetworkNode(tmp);
    network->length--;

    return network;
}

List *getNetworkOutputs(Network *network, List *inputs) {
    if (network == NULL || network->length == 0 || inputs == NULL || inputs->length == 0) {
        return NULL;
    }

    NetworkNode *It = network->head;
    List *outputs = inputs;
    while(It != NULL) {
        List* tmp = getClusterOutput(It->cluster, outputs);
        freeList(outputs);
        outputs = tmp;
        It = It->next;
    }

    return outputs;
}