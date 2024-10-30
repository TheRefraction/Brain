#ifndef NETWORK_H
#define NETWORK_H

#include "cluster.h"

typedef struct STRUCT_NNODE
{
    Cluster *cluster;
    struct STRUCT_NNODE *next;
    struct STRUCT_NNODE *prev;
} NetworkNode;

typedef struct
{
    int length;
    NetworkNode *head; // Input cluster
    NetworkNode *tail; // Output cluster
} Network;

NetworkNode *allocateNetworkNode(Cluster *cluster);
void freeNetworkNode(NetworkNode *node);

Network *allocateNetwork(unsigned int numOfClusters, List *numOfNeurons);
void freeNetwork(Network *network);

Network *insertHeadNetwork(Network *network, Cluster *cluster);
Network *insertTailNetwork(Network *network, Cluster *cluster);
Network *removeHeadNetwork(Network *network);
Network *removeTailNetwork(Network *network);

#endif //NETWORK_H
