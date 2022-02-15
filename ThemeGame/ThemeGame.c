#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include "GraphLib.h"

int inputRes;
int* nodeMarksTab;
GRAPH orGraph;

void initGame() {
    char user_chose;
    int nodeCount;
    srand(time(NULL));
    printf("Do you want to generate game configuration automatically, load it from your config file or enter configuration manualy? g/f/m: ");
    inputRes = scanf("%c", &user_chose);
    while ((user_chose != 'g') && (user_chose != 'f') && (user_chose != 'm'))
    {
        printf("Incorrect input!\nPlease, type \'g\' to generate game configuration automatically; type \'f\' to load game configuration from your config file; type \'m\' to enter game configuration manualy. g/f/m: ");
        inputRes = scanf("%c", &user_chose);
    }
    if (user_chose=='g')
    {
        nodeCount = rand() % 50 + 1;
        orGraph = initRandomGraph(nodeCount);
        nodeMarksTab = malloc((size_t)nodeCount * sizeof(int));
        for (size_t i = 0; i < nodeCount; i++) nodeMarksTab[i] = 0;
    }
    else if (user_chose == 'f') {
        char* config = malloc(sizeof(char));
        FILE* fin = NULL;
        printf("Enter path to config file: ");
        gets(config);
        if (config != "") fin = fopen(config, "r");
        while (fin==NULL)
        {
            printf("There is some problem opening the file. Check entered path and try again: ");
            gets(config);
            if (config != "") fin = fopen(config, "r");
        }
        inputRes = fscanf(fin, "%i", &nodeCount);
        orGraph = initEmptyGraph(nodeCount);
        nodeMarksTab = malloc((size_t)nodeCount * sizeof(int));
        for (size_t i = 0; i < nodeCount; i++) nodeMarksTab[i] = 0;
        for (int flag = 0, i = -1, j = -1; flag != EOF; flag = fscanf(fin, "%i%i", &i, &j))
            if ((i < nodeCount) && (j < nodeCount) && (i >= 0) && (j >= 0)) orGraph[i][j] = 1;
    }
    else if (user_chose == 'm')
    {
        printf("Firstly, enter number of nodes. Then define all links. Enter \"-1 -1\" to finish defining");
        inputRes = scanf("%i", &nodeCount);
        orGraph = initEmptyGraph(nodeCount);
        nodeMarksTab = malloc(nodeCount * sizeof(int));
        for (size_t i = 0; i < nodeCount; i++) nodeMarksTab[i] = 0;
        int i, j;
        inputRes = scanf("%i%i", &i, &j);
        for (; (i != -1) || (j != -1); inputRes = scanf("%i%i", &i, &j))
            if ((i < nodeCount) && (j < nodeCount) && (i >= 0) && (j >= 0)) orGraph[i][j] = 1;

    }
}

int main()
{
    initGame();

    printGraph(orGraph);
    printf("\n");
    int length = getGraphLength(orGraph);
    for (size_t i = 0; i < length; i++)
    {
        printf("%5d ", i);
    }
    printf("\n");
    for (size_t i = 0; i < length; i++)
    {
        printf("%5d ", nodeMarksTab[i]);
    }
    printf("\n");

    killGraph(orGraph);
    free(nodeMarksTab);
    return 0;
}