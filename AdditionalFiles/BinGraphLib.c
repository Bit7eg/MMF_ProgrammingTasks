#include <stdio.h>
#include <stdlib.h>
#include "BinGraphLib.h"
#include "ValueSetLib.h"

BIN_GRAPH initBinGraph() {
	BIN_GRAPH graph = malloc(sizeof(node));
	graph->mark = '\0';
	graph->minuseNode = NULL;
	graph->plusNode = NULL;
	return graph;
}

int getNodeCount(BIN_GRAPH graph) {
	unsigned int length = 0;
	while ((graph[length].mark != '\0') ||
		(graph[length].minuseNode != NULL) ||
		(graph[length].plusNode != NULL))
	{
		length++;
	}
	return length;
}

void killBinGraph(BIN_GRAPH graph) {
	free(graph);
}

int isLeaf(node vertex) {
	if ((vertex.mark >= '0') && (vertex.mark <= '9') && (vertex.minuseNode == NULL) && (vertex.plusNode == NULL))
	{
		return 1;
	}
	else if ((vertex.mark >= 'A') && (vertex.mark <= 'Z') && (vertex.minuseNode != NULL) && (vertex.plusNode != NULL))
	{
		return 0;
	}
	else
	{
		return -1;
	}
}

int isLogicalFragment(BIN_GRAPH graph) {
	int size = getNodeCount(graph);
	for (size_t i = 0; i < size; i++)
	{
		if (isLeaf(graph[i]) == -1)
		{
			return 0;
		}
	}
	return 1;
}

node* getNodePointer(BIN_GRAPH graph, char mark) {
	int size = getNodeCount(graph);
	for (size_t i = 0; i < size; i++)
	{
		if (graph[i].mark==mark)
		{
			return graph + i;
		}
	}
	return NULL;
}

BIN_GRAPH addNodesBin(BIN_GRAPH graph, char mark) {
	int size = getNodeCount(graph) + 1;
	graph = realloc(graph, (size+1) * sizeof(node));
	graph[size - 1].mark = mark;
	graph[size - 1].minuseNode = NULL;
	graph[size - 1].plusNode = NULL;
	graph[size].mark = '\0';
	graph[size].minuseNode = NULL;
	graph[size].plusNode = NULL;
	return graph;
}

VALUE_SET getVariableSet(BIN_GRAPH graph) {
	VALUE_SET vars = initValueSet();
	varValue var;
	int size = getNodeCount(graph);
	var.value = 0;
	for (size_t i = 0; i < size; i++)
	{
		if ((graph[i].mark >= 'A') && (graph[i].mark <= 'Z'))
		{
			var.name = graph[i].mark;
			vars = addVar(vars, var);
		}
	}
	return vars;
}

char logicalFragmentResult(BIN_GRAPH graph, VALUE_SET vars) {
	int graph_size = getNodeCount(graph), set_size = getVarCount(vars);
	varValue *varPointer, variable;
	node* vertex;
	if (!isLogicalFragment(graph))
	{
		return '\0';
	}
	VALUE_SET passedVertex = initValueSet();
	variable.value = 0;
	for (size_t i = 0; i < graph_size; i++)
	{
		if (!isLeaf(graph[i]))
		{
			varPointer = getVarPointerByName(vars, graph[i].mark);
			if (varPointer == NULL)
			{
				killValueSet(passedVertex);
				return '\0';
			}
			if ((varPointer->value != 1) && (varPointer->value != 0))
			{
				killValueSet(passedVertex);
				return '\0';
			}
			variable.name = graph[i].mark;
			passedVertex = addVar(passedVertex, variable);
		}
	}
	vertex = graph;
	varPointer = getVarPointerByName(passedVertex, vertex->mark);
	while (!isLeaf(*vertex))
	{
		if (varPointer->value)
		{
			killValueSet(passedVertex);
			return ('9' + 1);
		}
		varPointer->value = 1;
		varPointer = getVarPointerByName(vars, vertex->mark);
		if (varPointer->value)
		{
			vertex = vertex->plusNode;
		}
		else
		{
			vertex = vertex->minuseNode;
		}
		varPointer = getVarPointerByName(passedVertex, vertex->mark);
	}
	killValueSet(passedVertex);
	return vertex->mark;
}

BIN_GRAPH scanBinGraph() {
	char mark, plus, minuse;
	node* vmark, * vplus, * vminuse;
	BIN_GRAPH graph = initBinGraph();
	scanf("%c%c%c", &mark, &plus, &minuse);
	while ((mark >= 'A') && (mark <= 'Z'))
	{
		vmark = getNodePointer(graph, mark);
		if (vmark == NULL)
		{
			graph = addNodesBin(graph, mark);
			vmark = getNodePointer(graph, mark);
		}
		vplus = getNodePointer(graph, plus);
		if (vplus == NULL)
		{
			graph = addNodesBin(graph, plus);
			vplus = getNodePointer(graph, plus);
		}
		vminuse = getNodePointer(graph, minuse);
		if (vminuse == NULL)
		{
			graph = addNodesBin(graph, minuse);
			vminuse = getNodePointer(graph, minuse);
		}
		vmark->minuseNode = vminuse;
		vmark->plusNode = vplus;
		scanf("%c%c%c", &mark, &plus, &minuse);
	}
	return graph;
}

BIN_GRAPH fscanBinGraph(const char* fileName) {
	char mark, plus, minuse;
	node* vmark, * vplus, * vminuse;
	FILE* fin = fopen(fileName, "r");
	BIN_GRAPH graph = initBinGraph();
	while (!feof(fin))
	{
		fscanf(fin, "%c%c%c", &mark, &plus, &minuse);
		vmark = getNodePointer(graph, mark);
		if (vmark == NULL)
		{
			graph = addNodesBin(graph, mark);
			vmark = getNodePointer(graph, mark);
		}
		vplus = getNodePointer(graph, plus);
		if (vplus == NULL)
		{
			graph = addNodesBin(graph, plus);
			vplus = getNodePointer(graph, plus);
		}
		vminuse = getNodePointer(graph, minuse);
		if (vminuse == NULL)
		{
			graph = addNodesBin(graph, minuse);
			vminuse = getNodePointer(graph, minuse);
		}
		vmark->minuseNode = vminuse;
		vmark->plusNode = vplus;
	}
	fclose(fin);
	return graph;
}

void printBinGraph(BIN_GRAPH graph) {
	int size = getNodeCount(graph);
	printf("      ");
	for (size_t i = 0; i < size; i++)
	{
		printf(" %c", graph[i].mark);
	}
	printf("\nplus  ");
	for (size_t i = 0; i < size; i++)
	{
		printf(" %c", graph[i].plusNode->mark);
	}
	printf("\nminuse");
	for (size_t i = 0; i < size; i++)
	{
		printf(" %c", graph[i].minuseNode->mark);
	}
	printf("\n");
}