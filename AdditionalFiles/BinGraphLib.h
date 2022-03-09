#pragma once
#ifndef BINGRAPHLIB_H
#define BINGRAPHLIB_H

typedef struct node {
	int plusNode = -1;
	int minuseNode = -1;
} node;
typedef node* BIN_GRAPH;

int getAlphabetLength(BIN_GRAPH);
void killBinGraph(BIN_GRAPH);
BIN_GRAPH addNodesBin(int, int, int);
void printBinGraph(BIN_GRAPH);

#include "BinGraphLib.c"

#endif // !BINGRAPHLIB_H