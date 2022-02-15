#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "GraphLib.h"

GRAPH initEmptyGraph(int nodeCount) {
	GRAPH graph;
	graph = malloc(nodeCount * nodeCount * sizeof(short int));
	for (size_t i = 0; i < nodeCount; i++)
	{
		for (size_t j = 0; j < nodeCount; j++)
		{
			graph[i][j] = 0;
		}
	}
	return graph;
}

GRAPH initRandomGraph(int nodeCount) {
	srand(time(NULL));
	GRAPH graph;
	graph = malloc(nodeCount * nodeCount * sizeof(short int));
	for (size_t i = 0; i < nodeCount; i++)
	{
		for (size_t j = 0; j < nodeCount; j++)
		{
			graph[i][j] = rand() % 2;
		}
	}
	return graph;
}

int getGraphLength(GRAPH graph) {
	int sqrLength;
	sqrLength = sizeof(graph) / sizeof(short int);
	return sqrt(sqrLength);
}

void killGraph(GRAPH graph) {
	for (size_t i = 0; i < getGraphLength(graph); i++)
	{
		free(graph[i]);
	}
	free(graph);
}

GRAPH addNodes(GRAPH graph, int nodeCount) {
	int resLength, graphLength;
	graphLength = getGraphLength(graph);
	resLength = graphLength + nodeCount;
	if (resLength < graphLength) {
		resLength = INT_MAX;
	}
	graph = realloc(graph, resLength * resLength * sizeof(short int));
	for (size_t i = 0; i < graphLength; i++)
	{
		for (size_t j = graphLength; j < resLength; j++)
		{
			graph[i][j] = 0;
		}
	}
	for (size_t i = graphLength; i < resLength; i++)
	{
		for (size_t j = 0; j < resLength; j++)
		{
			graph[i][j] = 0;
		}
	}
	return graph;
}

GRAPH removeNodes(GRAPH graph, int nodeCount) {
	int resLength;
	resLength = getGraphLength(graph) - nodeCount;
	GRAPH newGraph;
	newGraph = NULL;
	if (resLength > 0) {
		newGraph = malloc(resLength * resLength * sizeof(short int));
		for (size_t i = 0; i < resLength; i++)
		{
			for (size_t j = 0; j < resLength; j++)
			{
				newGraph[i][j] = graph[i][j];
			}
		}
	}
	killGraph(graph);
	return newGraph;
}

void printGraph(GRAPH graph) {
	int size = getGraphLength(graph);
	printf("    ");
	for (size_t i = 0; i < size; i++)
	{
		printf("%3d ", i);
	}
	printf("\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%3d ", i);
		for (size_t j = 0; j < size; j++)
		{
			printf("%3hd ", graph[i][j]);
		}
		printf("\n");
	}
}