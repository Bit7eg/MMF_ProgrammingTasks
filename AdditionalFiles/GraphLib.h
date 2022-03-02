#ifndef GRAPHLIB_H
#define GRAPHLIB_H

typedef int** GRAPH;

GRAPH initEmptyGraph(int);
GRAPH initRandomGraph(int);
int getGraphLength(GRAPH);
void killGraph(GRAPH);
GRAPH addNodes(GRAPH, int);
GRAPH removeNodes(GRAPH, int);
void printGraph(GRAPH);

#endif // !GRAPHLIB_H