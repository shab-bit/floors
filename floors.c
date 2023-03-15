#include <stdio.h>
#include <stdlib.h>
#define maxlev 1
int main()
{
    int po[2] = {0, 0}, level = 0, had = 20;
    while (1)
    {
        system("cls");
        printf("\t\t\tlevel %d \n", level + 1);
        switch (level)
        {
        case 0:
            one(po, &had);
            break;

        case 1:
            two(po, &had);
            break;

        default:
            printf("\n\t\t\t\t\tEROR AT DETECT LEVEL\n");
            break;
        }

        switch (getch())
        {
        case 'w':
            if (po[0] > 0)
            {
                po[0]--;
            }

            break;
        case 's':
            if (po[0] < had - 1)
            {
                po[0]++;
            }
            break;
        case 'd':
            if (po[1] < had - 2)
            {
                po[1]++;
            }
            break;
        case 'a':
            if (po[1] > 0)
            {
                po[1]--;
            }
            break;

        default:
            break;
        }
        if (po[0] == 12 && po[1] == 12)
        {
            if (level < maxlev)
            {
                level++;
                po[0] = 13;
                po[1] = 12;
            }
        }
        if (po[0] == 10 && po[1] == 12)
        {
            if (level)
            {
                level--;
                po[0] = 9;
                po[1] = 12;
            }
        }
    }
}

/*one*/
int one(int po[2], int *had)
{
    for (int i = 0; i < *had + 1; i++)
    {
        printf("# ");
    }
    for (int i = 0; i < *had; i++)
    {
        printf("\n#");
        for (int j = 0; j < *had - 1; j++)
        {
            if (po[0] == i && po[1] == j)
            {
                printf(" 8");
            }
            else if (i == 12 && j == 12)
            {
                printf(" #");
            }
            else if (i == 10 && j == 12)
            {
                printf(" $");
            }
            else
            {
                printf("  ");
            }
        }
        printf(" #");
    }
    printf("\n");
    for (int i = 0; i < *had + 1; i++)
    {
        printf("# ");
    }
}

/*two*/
int two(int po[2], int *had)
{
    for (int i = 0; i < *had + 1; i++)
    {
        printf("# ");
    }
    for (int i = 0; i < *had; i++)
    {
        printf("\n#");
        for (int j = 0; j < (*had - 1) * 2; j++)
        {
            if (po[0] == i && po[1] == j)
            {
                printf(" 8");
            }
            else if (i == 12 && j == 12)
            {
                printf(" #");
            }
            else if (i == 10 && j == 12)
            {
                printf(" $");
            }
            else
            {
                printf("  ");
            }
        }
        printf(" #");
    }
    printf("\n");
    for (int i = 0; i < *had + 1; i++)
    {
        printf("# ");
    }
}