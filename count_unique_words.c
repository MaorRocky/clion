#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

//
// Created by maor on 10/11/2020.
//
void count();

int main()
{
    count();
    return 0;
}

void count()
{
    int count;
    char word[101][40];
    FILE *fp;

    if ((fp = fopen("input.txt", "r")) == NULL)
        exit(1);

    for (count = 0; count < 101; count++)
    {
        if (fscanf(fp, "%39s", word[count]) != 1)
            break;
    }

    fclose(fp);


    int i, j, unique, repeated;

    unique = 0;
    for (i = 0; i < count; i++)
    {
        repeated = 0;
        for (j = 0; j < i; j++)
            if (strcmp(word[i], word[j]) == 0)
            {
                repeated = 1;
                break;
            }

        if (!repeated)
        {
            unique++;
            printf("%s\n", word[i]);
        }
    }

    printf("The number of unique words is %d\n", unique);
}