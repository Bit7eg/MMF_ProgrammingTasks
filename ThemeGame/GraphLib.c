#include <stdlib.h>
#include <math.h>

short int** initEmptyGraph(int nodeCount) {
	short int** graph;
	graph = (short int**)malloc(nodeCount * sizeof(short int*));
	for (size_t i = 0; i < nodeCount; i++)
	{
		graph[i] = (short int*) malloc(nodeCount * sizeof(short int));
		for (size_t j = 0; j < nodeCount; j++)
		{
			graph[i][j] = 0;
		}
	}
	return graph;
}

short int** initRandomGraph(int nodeCount) {
	short int** graph;
	graph = (short int**)malloc(nodeCount * sizeof(short int*));
	for (size_t i = 0; i < nodeCount; i++)
	{
		graph[i] = (short int*)malloc(nodeCount * sizeof(short int));
		for (size_t j = 0; j < nodeCount; j++)
		{
			graph[i][j] = rand() % 2;
		}
	}
	return graph;
}

int getGraphLength(short int** graph) {
	int sqrLength;
	sqrLength = sizeof(graph) / sizeof(short int);
	return sqrt(sqrLength);
}

void killGraph(short int** graph) {
	for (size_t i = 0; i < getGraphLength(graph); i++)
	{
		free(graph[i]);
	}
	free(graph);
}

short int** addNodes(short int** graph, int nodeCount) {
	int resLength, graphLength;
	graphLength = getGraphLength(graph);
	resLength = graphLength + nodeCount;
	if (resLength < graphLength) {
		resLength = INT_MAX;
	}
	short int** newGraph;
	newGraph = (short int**)malloc(resLength * sizeof(short int*));
	for (size_t i = 0; i < graphLength; i++)
	{
		newGraph[i] = (short int*)malloc(resLength * sizeof(short int));
		for (size_t j = 0; j < graphLength; j++)
		{
			newGraph[i][j] = graph[i][j];
		}
		for (size_t j = graphLength; j < resLength; j++)
		{
			newGraph[i][j] = 0;
		}
	}
	for (size_t i = graphLength; i < resLength; i++)
	{
		newGraph[i] = (short int*)malloc(resLength * sizeof(short int));
		for (size_t j = 0; j < resLength; j++)
		{
			newGraph[i][j] = 0;
		}
	}
	killGraph(graph);
	return newGraph;
}

short int** removeNodes(short int** graph, int nodeCount) {
	int resLength;
	resLength = getGraphLength(graph) - nodeCount;
	short int** newGraph;
	newGraph = NULL;
	if (resLength > 0) {
		newGraph = (short int**)malloc(resLength * sizeof(short int*));
		for (size_t i = 0; i < resLength; i++)
		{
			newGraph[i] = (short int*)malloc(resLength * sizeof(short int));
			for (size_t j = 0; j < resLength; j++)
			{
				newGraph[i][j] = graph[i][j];
			}
		}
	}
	killGraph(graph);
	return newGraph;
}