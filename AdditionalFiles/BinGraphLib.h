#ifndef BINGRAPHLIB_H
#define BINGRAPHLIB_H

typedef int*[2] BIN_GRAPH;

BIN_GRAPH initEmptyBinGraph(int);
BIN_GRAPH initRandomBinGraph(int);
int getBinGraphLength(BIN_GRAPH);
void killBinGraph(BIN_GRAPH);
BIN_GRAPH addNodesBin(BIN_GRAPH, int);
BIN_GRAPH removeNodesBin(BIN_GRAPH, int);
void printBinGraph(BIN_GRAPH);

#endif // !BINGRAPHLIB_H