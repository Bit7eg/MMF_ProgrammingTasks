#pragma once
#ifndef BINGRAPHLIB_H
#define BINGRAPHLIB_H

#include "ValueSetLib.h"

typedef struct node {
	char mark;
	struct node* plusNode;
	struct node* minuseNode;
} node;
typedef node* BIN_GRAPH;

BIN_GRAPH initBinGraph();
int getNodeCount(BIN_GRAPH);
void killBinGraph(BIN_GRAPH);
int isLeaf(node);
int isLogicalFragment(BIN_GRAPH);
node* getNodePointer(BIN_GRAPH, char);
BIN_GRAPH addNodesBin(BIN_GRAPH, char);
VALUE_SET getVariableSet(BIN_GRAPH);
char logicalFragmentResult(BIN_GRAPH, VALUE_SET);
BIN_GRAPH scanBinGraph();
BIN_GRAPH fscanBinGraph(const char*);
void printBinGraph(BIN_GRAPH);

#include "BinGraphLib.c"

#endif // !BINGRAPHLIB_H