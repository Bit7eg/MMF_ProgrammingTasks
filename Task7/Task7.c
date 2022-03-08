#include <stdio.h>
#include "GraphLib.h"

int main()
{
    int nodeCount;
    scanf("%i", &nodeCount);
    GRAPH graph = initEmptyGraph(nodeCount);
    int fromVertex = 0, toVertex = 0, dist = 0;
    scanf("%i%i%i", &fromVertex, &toVertex, &dist);
    while ((fromVertex > 0) && (toVertex > 0) && (dist > 0))
    {
        graph[(--fromVertex)][(--toVertex)] = dist;
        scanf("%i%i%i", &fromVertex, &toVertex, &dist);
    }
    GRAPH distMatrix = getDistanceMatrix(graph);
    printf("\n");
    printGraph(distMatrix);
    killGraph(distMatrix);
    killGraph(graph);
}