#include <stdio.h>
#include "GraphLib.h"

void pow3noCycle3(GRAPH graph, size_t size)
{
    if (size > 3)
    {
        graph = addLink(graph, size - 1, size - 2);
        graph = addLink(graph, size - 1, size - 1);
        graph = addLink(graph, size - 2, size - 2);
        pow3noCycle3(graph, size - 2);
    }
    else if (size == 3) {

    }
    else if (size == 2)
    {
        graph = addLink(graph, 1, 0);
        graph = addLink(graph, 1, 1);
        graph = addLink(graph, 0, 0);
    }
    else
    {
        killGraph(graph);
        graph = NULL;
    }
}

void tryGenGraph(int size) {

}

int main()
{
    for (int i = 1; i < 15; i+=2)
    {

    }
}