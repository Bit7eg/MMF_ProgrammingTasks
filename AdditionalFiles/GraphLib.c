#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>
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

GRAPH initRandomGraph(int nodeCount) {
	srand(time(NULL));
	GRAPH graph;
	graph = calloc(nodeCount, sizeof(int*));
	for (size_t i = 0; i < nodeCount; i++)
	{
		graph[i] = calloc(nodeCount, sizeof(int));
		for (size_t j = 0; j < nodeCount; j++)
		{
			graph[i][j] = rand() % (INT_MAX - 1);
		}
	}
	return graph;
}

GRAPH getDistanceMatrix(GRAPH graph, int nodeCount) {
	GRAPH resultDistanceMatrix, stepDistanceMatrix;
	resultDistanceMatrix = calloc(nodeCount, sizeof(int*));
	stepDistanceMatrix = calloc(nodeCount, sizeof(int*));
	for (size_t i = 0; i < nodeCount; i++)
	{
		resultDistanceMatrix[i] = calloc(nodeCount, sizeof(int));
		stepDistanceMatrix[i] = calloc(nodeCount, sizeof(int));
		for (size_t j = 0; j < nodeCount; j++)
		{
			if (i==j)
			{
				resultDistanceMatrix[i][j] = 0;
				stepDistanceMatrix[i][j] = 0;
			}
			else
			{
				if (graph[i][j]!=0)
				{
					resultDistanceMatrix[i][j] = graph[i][j];
					stepDistanceMatrix[i][j] = graph[i][j];
				}
				else
				{
					resultDistanceMatrix[i][j] = INT_MAX;
					stepDistanceMatrix[i][j] = INT_MAX;
				}
			}
		}
	}
	GRAPH buff = initEmptyGraph(nodeCount);
	int min, sum;
	for (size_t k = 2; k < nodeCount; k++)
	{
		for (size_t i = 0; i < nodeCount; i++)
		{
			for (size_t j = 0; j < nodeCount; j++)
			{
				if (i!=j)
				{
					min = INT_MAX;
					for (size_t h = 0; h < nodeCount; h++)
					{
						sum = resultDistanceMatrix[i][h] + stepDistanceMatrix[h][j];
						if ((sum >= 0) && (min > sum))
						{
							min = sum;
						}
					}
					buff[i][j] = min;
				}
			}
		}
		for (size_t i = 0; i < nodeCount; i++)
		{
			for (size_t j = 0; j < nodeCount; j++)
			{
				resultDistanceMatrix[i][j] = buff[i][j];
			}
		}
	}
	killGraph(buff, nodeCount);
	killGraph(stepDistanceMatrix, nodeCount);
	return resultDistanceMatrix;
}

void killGraph(GRAPH graph, int size) {
	for (size_t i = 0; i < size; i++)
	{
		free(graph[i]);
	}
	free(graph);
}

GRAPH addNodes(GRAPH graph, int graphLength, int nodeCount) {
	int resLength;
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

GRAPH removeNodes(GRAPH graph, int size, int nodeCount) {
	int resLength;
	resLength = size - nodeCount;
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
	killGraph(graph, size);
	return newGraph;
}

GRAPH addLink(GRAPH graph, int v1, int v2) {
	graph[v1][v2]++;
	graph[v2][v1]++;
	return graph;
}

GRAPH deleteLink(GRAPH graph, int v1, int v2) {
	graph[v1][v2]++;
	graph[v2][v1]++;
	return graph;
}

void printGraph(GRAPH graph, int size) {
	printf("           ");
	for (size_t i = 0; i < size; i++)
	{
		printf("%10i ", i + 1);
	}
	printf("\n");
	for (size_t i = 0; i < size; i++)
	{
		printf("%10i ", i + 1);
		for (size_t j = 0; j < size; j++)
		{
			if (graph[i][j]==INT_MAX)
			{
				printf("       inf ");
			}
			else
			{
				printf("%10i ", graph[i][j]);
			}
		}
		printf("\n");
	}
}