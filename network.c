#include "network.h"

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

Network *allocateNetwork(const unsigned int numOfClusters, const List *numOfNeurons)
{
    if(numOfNeurons == NULL || numOfClusters == 0 || numOfNeurons->length != numOfClusters)
    {
        return NULL;
    }

    Network *network = malloc(sizeof(Network));
    network->head = NULL;
    network->tail = NULL;
    network->length = 0;

    Node *It = numOfNeurons->head;
    while(It != NULL)
    {
        Cluster *cluster = allocateCluster(It->value, 1); // FIXME: numOfInputs not clear ??
        network = insertHeadNetwork(network, cluster);

        It = It->next;
    }

    return network;
}

void freeNetwork(Network *network)
{
    if(network != NULL)
    {
        while(network->length > 0) {
            network = removeHeadCluster(network);
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
