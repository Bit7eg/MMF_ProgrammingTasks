#pragma once
#ifndef GRAPHLIB_H
#define GRAPHLIB_H

typedef int** GRAPH;

GRAPH initEmptyGraph(int);
GRAPH initRandomGraph(int);
unsigned int getGraphLength(GRAPH);
GRAPH getDistanceMatrix(GRAPH);
void killGraph(GRAPH);
GRAPH addNodes(GRAPH, int);
GRAPH removeNodes(GRAPH, int);
void printGraph(GRAPH);

#include "GraphLib.c"

#endif // !GRAPHLIB_H