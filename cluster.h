#ifndef CLUSTER_H
#define CLUSTER_H

#include "neuron.h"

/**
 * definition of a new structure "ClusterNode" who is a link list of neurons
 */
typedef struct STRUCT_CNODE
{
    Neuron *neuron;
    struct STRUCT_CNODE *next;
    struct STRUCT_CNODE *prev;
} ClusterNode;

/**
 * definition of a new structure "CLuster" with the length and the head and the tail
 */
typedef struct
{
    int length;
    ClusterNode *head;
    ClusterNode *tail;
} Cluster;

/**
 * allocate the memory for a new ClusterNode
 * @param neuron
 * @return
 */
ClusterNode *allocateClusterNode(Neuron *neuron);

/**
 * free the memory of a cluster node
 * @param node
 */
void freeClusterNode(ClusterNode *node);

/**
 * allocate memory for a new cluster
 * @param numOfNeurons
 * @param numOfInputs
 * @return cluster
 */
Cluster *allocateCluster(unsigned int numOfNeurons, unsigned int numOfInputs);

/**
 * free the memory of a cluster
 * @param cluster
 */
void freeCluster(Cluster *cluster);

/**
 * insert a neuron in head of a cluster
 * @param cluster
 * @param neuron
 * @return
 */
Cluster *insertHeadCluster(Cluster *cluster, Neuron *neuron);

/**
 * insert a neuron in tail of a cluster
 * @param cluster
 * @param neuron
 * @return
 */
Cluster *insertTailCluster(Cluster *cluster, Neuron *neuron);

/**
 * remove the head of a cluster
 * @param cluster
 * @return the cluster without the head
 */
Cluster *removeHeadCluster(Cluster *cluster);

/**
 * remove the tail of a cluster
 * @param cluster
 * @return the cluster without the tail
 */
Cluster *removeTailCluster(Cluster *cluster);

/**
 *
 * @param cluster
 * @param inputs
 * @return
 */
List *getClusterOutput(Cluster *cluster, List *inputs);


#endif //CLUSTER_H