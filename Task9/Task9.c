#include <stdio.h>

int main()
{
    FILE* fin = fopen("input.cpp", "r"), * fout = fopen("output.cpp", "w");
    char ch;
    int fl = 0;
    while (!feof(fin))
    {
        fscanf(fin, "%c", &ch);
        switch (fl)
        {
            case -1: {
                if ('\"' == ch)
                {
                    fl = 0;
                }
                break;
            }
            case 0: {
                if ('/' == ch)
                {
                    fl = 1;
                }
                else if ('\"' == ch)
                {
                    fl = -1;
                }
                break;
            }
            case 1: {
                if ('/' == ch)
                {
                    fl = 2;
                }
                else if ('*' == ch)
                {
                    fl = 3;
                }
                else
                {
                    fprintf(fout, "/");
                    fl = 0;
                }
                break;
            }
            case 2: {
                if ('\n' == ch)
                {
                    fl = 5;
                }
                break;
            }
            case 3: {
                if ('*' == ch)
                {
                    fl = 4;
                }
                break;
            }
            case 4: {
                if ('/' == ch)
                {
                    fl = 5;
                }
                else if ('*' != ch)
                {
                    fl = 3;
                }
                break;
            }
            case 5: {
                if ('/' == ch)
                {
                    fl = 1;
                }
                else if ('\"' == ch)
                {
                    fl = -1;
                }
                else
                {
                    fl = 0;
                }
                break;
            }
            default: {
                printf("Something went wrong");
                return 0;
                break;
            }
        }
        if (fl < 1)
        {
            fprintf(fout, "%c", ch);
        }
    }
    printf("Successfully completed");
    fclose(fin);
    fclose(fout);
    return 0;
}