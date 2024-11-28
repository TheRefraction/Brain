#ifndef NETWORK_H
#define NETWORK_H

#include "cluster.h"

/**
 * definition of a new structure "NetworkNode" who is a link list of cluster
 */
typedef struct STRUCT_NNODE
{
    Cluster *cluster;
    struct STRUCT_NNODE *next;
    struct STRUCT_NNODE *prev;
} NetworkNode;

/**
 *
 */
typedef struct
{
    int length;
    NetworkNode *head; // Input cluster
    NetworkNode *tail; // Output cluster
} Network;

/**
 * allocate memory for a new network node
 * @param cluster
 * @return
 */
NetworkNode *allocateNetworkNode(Cluster *cluster);

/**
 * free a network node
 * @param node
 */
void freeNetworkNode(NetworkNode *node);

/**
 * allocate memory for a new network
 * @param numOfClusters
 * @param numOfNeurons
 * @param numOfInputs of the first cluster
 * @return
 */
Network *allocateNetwork(unsigned int numOfClusters, List *numOfNeurons, unsigned int numOfInputs);

/**
 * free a network
 * @param network
 */
void freeNetwork(Network *network);

/**
 * insert a cluster in head of a network
 * @param network
 * @param cluster
 * @return
 */
Network *insertHeadNetwork(Network *network, Cluster *cluster);

/**
 * inset a cluster in tail of a network
 * @param network
 * @param cluster
 * @return
 */
Network *insertTailNetwork(Network *network, Cluster *cluster);

/**
 * remove the head of a network
 * @param network
 * @return
 */
Network *removeHeadNetwork(Network *network);

/**
 * remove the tail of a network
 * @param network
 * @return
 */
Network *removeTailNetwork(Network *network);

List *getNetworkOutputs(Network *network, List *inputs);

#endif //NETWORK_H
