#ifndef CLUSTER_H
#define CLUSTER_H

#include "neuron.h"

typedef struct STRUCT_CNODE {
    Neuron *neuron;
    struct STRUCT_CNODE *next;
    struct STRUCT_CNODE *prev;
} ClusterNode;

typedef struct {
    int length;
    ClusterNode *head;
    ClusterNode *tail;
} Cluster;

#endif //CLUSTER_H

/*today's word in pedantix was “aerodynamics”.*/