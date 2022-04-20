#pragma once
#ifndef GRAPHLIB_H
#define GRAPHLIB_H

typedef int** GRAPH;

GRAPH initEmptyGraph(int);
GRAPH initRandomGraph(int);
GRAPH getDistanceMatrix(GRAPH);
void killGraph(GRAPH);
GRAPH addNodes(GRAPH, int);
GRAPH removeNodes(GRAPH, int);
GRAPH addLink(GRAPH, int, int);
GRAPH deleteLink(GRAPH, int, int);
void printGraph(GRAPH);

#include "GraphLib.c"

#endif // !GRAPHLIB_H