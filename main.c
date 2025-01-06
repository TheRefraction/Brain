#include <stdio.h>
#include <stdlib.h>

#include "network.h"

int main(int argc, const char* argv[]) {
    Network *network = NULL;

    short action = 0;

    while (action != 3)
    {
        printf("What action do you want to perform?\n1)Create Network\n2)Get output\n3)Exit\n-----\nChoice:");
        scanf("%hd", &action);
        while (action <= 0 || action > 3) {
            printf("Invalid Input!\nChoice:");
            scanf("%hd", &action);
        }

        switch (action)
        {
            case 1:
                {
                    printf("Network creation\n--------------------\n");

                    freeNetwork(network);

                    printf("Enter number of Clusters:");
                    int numOfClusters;
                    scanf("%d", &numOfClusters);
                    while (numOfClusters <= 0)
                    {
                        printf("Invalid Input!\nEnter number of Clusters:");
                        scanf("%d", &numOfClusters);
                    }

                    printf("Enter number of inputs:");
                    int numOfInputs;
                    scanf("%d", &numOfInputs);
                    while (numOfInputs <= 0)
                    {
                        printf("Invalid Input!\nEnter number of inputs:");
                        scanf("%d", &numOfInputs);
                    }

                    List *numOfNeurons = NULL;
                    int tmp;
                    for (int i = 0; i < numOfClusters; i++)
                    {
                        printf("Enter number of neurons for cluster %d:", i + 1);
                        scanf("%d", &tmp);
                        while (tmp <= 0)
                        {
                            printf("Invalid Input!\nEnter number of neurons for cluster %d:", i + 1);
                            scanf("%d", &tmp);
                        }

                        numOfNeurons = insertTailList(numOfNeurons, tmp);
                    }

                    network = allocateNetwork(numOfClusters, numOfNeurons, numOfInputs);
                    freeList(numOfNeurons);

                    break;
                }
            case 2:
                {
                    if (network == NULL)
                    {
                        printf("Error! Network is NULL\n");
                        break;
                    }

                    printf("Network evaluation\n--------------------\n");

                    List *inputs = NULL;
                    int tmp;
                    for (int i = 0; i < network->numOfInputs; i++)
                    {
                        printf("Enter input %d:", i + 1);
                        scanf("%d", &tmp);
                        inputs = insertTailList(inputs, tmp);
                    }

                    inputs = getNetworkOutputs(network, inputs);
                    printf("Output >>");
                    printList(inputs, 1);
                    freeList(inputs);

                    break;
                }
        }
        printf("====================\n");
    }

    printf("Goodbye!\n");

    freeNetwork(network);

    return 0;
}
