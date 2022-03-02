#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include "GraphLib.h"

GRAPH initEmptyGraph(int nodeCount) {
	GRAPH graph;
	graph = calloc(nodeCount, sizeof(int*));
	for (size_t i = 0; i < nodeCount; i++)
	{
		graph[i] = calloc(nodeCount, sizeof(int));
		for (size_t j = 0; j < nodeCount; j++)
		{
			graph[i][j] = 0;
		}
	}
	return graph;
}

int getGraphLength(GRAPH graph) {
	int sqrLength;
	sqrLength = sizeof(graph[0]) / sizeof(int);
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
	graph = realloc(graph, resLength * sizeof(int*));
	for (size_t i = 0; i < graphLength; i++)
	{
		graph[i] = realloc(graph[i], resLength * sizeof(int));
		for (size_t j = graphLength; j < resLength; j++)
		{
			graph[i][j] = 0;
		}
	}
	for (size_t i = graphLength; i < resLength; i++)
	{
		graph[i] = realloc(graph[i], resLength * sizeof(int));
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
		newGraph = calloc(resLength, sizeof(int*));
		for (size_t i = 0; i < resLength; i++)
		{
			newGraph[i] = calloc(resLength, sizeof(int));
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
		printf("%3i ", i);
	}
	printf("\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%3i ", i);
		for (size_t j = 0; j < size; j++)
		{
			printf("%3hi ", graph[i][j]);
		}
		printf("\n");
	}
}