#include <stdio.h>
#include <time.h>

#include "GraphLib.h"

#define DEBUG 0;

GRAPH pow3noCycle3(size_t size)
{
    if (size % 2 == 0)
    {
        GRAPH graph = initEmptyGraph(size);
        for (int i = size / 2 - 1; i >= 0; i--)
        {
            graph = addLink(graph, 2 * i, 2 * i);
            graph = addLink(graph, 2 * i, 2 * i + 1);
            graph = addLink(graph, 2 * i + 1, 2 * i + 1);
        }
        return graph;
    }
    else
    {
        return NULL;
    }
}

int main()
{
    srand(time(NULL));
    int size;

#if DEBUG
    size = 6;
    printf("%i\n", size);
#else
    scanf("%i", &size);
#endif

    GRAPH graph = pow3noCycle3(size);
    graph ? printGraph(graph, size) : printf("Impossible for odd numbers");
}