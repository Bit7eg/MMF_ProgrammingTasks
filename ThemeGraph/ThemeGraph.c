#include <stdio.h>
#include "GraphLib.h"

void pow3noCycle3(GRAPH graph, size_t size)
{
    if (size > 3)
    {
        graph[size - 1][size - 2] = 1;
        graph[size - 1][size - 1] = 1;
        graph[size - 2][size - 1] = 1;
        graph[size - 2][size - 2] = 1;
        pow3noCycle3(graph, size - 2);
    }
    else if (size == 3) {

    }
    else if (size == 2)
    {
        graph[0][1] = 1;
        graph[0][0] = 1;
        graph[1][0] = 1;
        graph[1][1] = 1;
    }
    else
    {
        graph = NULL;
    }
}

int main()
{
    int nodeCount = 1;
    scanf("%i", &nodeCount);
    GRAPH graph = initEmptyGraph(nodeCount);
    pow3noCycle3(graph, nodeCount);
    printGraph(graph);
}