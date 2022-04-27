#include <stdio.h>
#include <time.h>

#define DEBUG 1;

struct cell {
    int number;
    char letter;
};

int** generateBoard()
{
    int board[8][8], whiteCount = 0, blackCount = 0;
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            if ((i % 2 == j % 2) && (whiteCount < 12 || blackCount < 12))
            {
                board[i][j] = rand() % 5 - 2;
                if (board[i][j] > 0)
                {
                    if (whiteCount >= 12)
                    {
                        board[i][j] = -board[i][j];
                        blackCount++;
                    }
                    else
                    {
                        whiteCount++;
                    }
                }
                else if (board[i][j] < 0)
                {
                    if (blackCount >= 12)
                    {
                        board[i][j] = -board[i][j];
                        whiteCount++;
                    }
                    else
                    {
                        blackCount++;
                    }
                }
            }
            else
            {
                board[i][j] = 0;
            }
        }
    }
    return board;
}

int** scanBoard()
{
    int board[8][8];
    for (size_t i = 0; i < 8; i++)
    {
        for (size_t j = 0; j < 8; j++)
        {
            board[i][j] = 0;
        }
    }
    int i;
    char j, ch;
    scanf("%i%c", &i, &j);
    while (i >= 1 && i <= 8 && j >= 'A' && j <= 'H')
    {
        scanf("%i", &ch);
        if (ch == 'w')
        {
            board[i - 1][(int)(j - 'A')] = 1;
        }
        else if (ch == 'b')
        {
            board[i - 1][(int)(j - 'A')] = -1;
        }
        else if (ch == 'W')
        {
            board[i - 1][(int)(j - 'A')] = 2;
        }
        else if (ch == 'B')
        {
            board[i - 1][(int)(j - 'A')] = -2;
        }
        scanf("%i%c", &i, &j);
    }
    return board;
}

void printBoard(int board[8][8])
{
    printf(" ");
    for (size_t j = 0; j < 8; j++)
    {
        printf(" %c", ((char)j + 'A'));
    }
    printf("\n");
    for (size_t i = 0; i < 8; i++)
    {
        printf("%i", i);
        for (size_t j = 0; j < 8; j++)
        {
            printf(" %2i", board[i][j]);
        }
        printf("\n");
    }
}

int main()
{
    int** board;

#if DEBUG
    board = generateBoard();
#else
    board = scanBoard();
#endif // DEBUG

    printBoard(board);
    struct cell from = { 0, 0 }, to = { 0, 0 };
    int fl = 0;
    for (size_t i = 0; i < 8 && !fl; i++)
    {
        for (size_t j = i % 2; j < 8 && !fl; j += 2)
        {
            if (board[i][j] > 0)
            {
                from.letter = j + 'A';
                from.number = i + 1;
                if (i < 7 && j > 0 && board[i + 1][j - 1] == 0)
                {
                    to.letter = j - 1 + 'A';
                    to.number = i + 2;
                    fl = 1;
                }
                else if (i < 7 && j < 7 && board[i + 1][j + 1] == 0)
                {
                    to.letter = j + 1 + 'A';
                    to.number = i + 2;
                    fl = 1;
                }
                else if (i < 6 && j > 1 && board[i + 1][j - 1] < 0 && board[i + 2][j - 2] == 0)
                {
                    to.letter = j - 2 + 'A';
                    to.number = i + 3;
                    fl = 1;
                }
                else if (i < 6 && j < 6 && board[i + 1][j + 1] < 0 && board[i + 2][j + 2] == 0)
                {
                    to.letter = j + 2 + 'A';
                    to.number = i + 3;
                    fl = 1;
                }
                else if (i > 1 && j > 1 && board[i - 1][j - 1] < 0 && board[i - 2][j - 2] == 0)
                {
                    to.letter = j - 2 + 'A';
                    to.number = i - 1;
                    fl = 1;
                }
                else if (i > 1 && j < 6 && board[i - 1][j + 1] < 0 && board[i - 2][j + 2] == 0)
                {
                    to.letter = j + 2 + 'A';
                    to.number = i - 1;
                    fl = 1;
                }
                else if(i > 0 && j > 0 && board[i][j] == 2 && board[i - 1][j - 1] == 0)
                {
                    to.letter = j - 1 + 'A';
                    to.number = i;
                    fl = 1;
                }
                else if (i > 0 && j < 7 && board[i][j] == 2 && board[i - 1][j + 1] == 0)
                {
                    to.letter = j + 1 + 'A';
                    to.number = i;
                    fl = 1;
                }
            }
        }
    }
    if (fl)
    {
        printf("One of available move is %c%i -> %c%i", from.letter, from.number, to.letter, to.number);
    }
    else
    {
        printf("There is no one available move");
    }
    return 0;
}