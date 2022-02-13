#include <stdio.h>
#include <time.h>
#include "GraphLib.c"

int* nodesList;
short int** orGraph;

void initGame() {
    char user_chose;
    int nodeCount;
    srand(time(NULL));
    printf("Do you want to generate game configuration automatically, load it from your config file or enter configuration manualy? g/f/m: ");
    scanf("%c", user_chose);
    while ((user_chose != 'g') && (user_chose != 'f') && (user_chose != 'm'))
    {
        printf("Incorrect input!\nPlease, type \'g\' to generate game configuration automatically; type \'f\' to load game configuration from your config file; type \'m\' to enter game configuration manualy. g/f/m: ");
        scanf("%c", user_chose);
    }
    if (user_chose=='g')
    {
        nodeCount = rand() % 50 + 1;
        orGraph = initRandomGraph(nodeCount);
        nodesList = malloc(nodeCount * sizeof(int));
        for (size_t i = 0; i < nodeCount; i++) nodesList[i] = 0;
    }
    else if (user_chose == 'f') {
        char* config;
        FILE* fin;
        printf("Enter path to config file: ");
        gets(config);
        fin = fopen(config, "r");
        while (fin==NULL)
        {
            printf("There is some problem opening the file. Check entered path and try again: ");
            gets(config);
            fin = fopen(config, "r");
        }
        fscanf(fin, "%i", &nodeCount);
        orGraph = initEmptyGraph(nodeCount);
        nodesList = malloc(nodeCount * sizeof(int));
        for (size_t i = 0; i < nodeCount; i++) nodesList[i] = 0;
        for (int flag = 0, i = -1, j = -1; flag != EOF; flag = fscanf(fin, "%i%i", &i, &j))
            if ((i < nodeCount) && (j < nodeCount) && (i >= 0) && (j >= 0)) orGraph[i][j] = 1;
    }
    else if (user_chose == 'm')
    {
        printf("Firstly, enter number of nodes. Then define all links. Enter \"-1 -1\" to finish defining");
        scanf("%i", &nodeCount);
        orGraph = initEmptyGraph(nodeCount);
        nodesList = malloc(nodeCount * sizeof(int));
        for (size_t i = 0; i < nodeCount; i++) nodesList[i] = 0;
        int i, j;
        scanf("%i%i", &i, &j);
        for (; (i != -1) || (j != -1); scanf("%i%i", &i, &j))
            if ((i < nodeCount) && (j < nodeCount) && (i >= 0) && (j >= 0)) orGraph[i][j] = 1;

    }
}

int main()
{
    initGame();


    killGraph(orGraph);
    free(nodesList);
    return 0;
}