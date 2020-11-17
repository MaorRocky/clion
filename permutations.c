//
// Created by maor on 02/11/2020.
//


#include <stdio.h>
#include <string.h>

void permuteArr(int *a, int l, int r);

void permute(char *a, int l, int r);

int length(char *s);

void swap(char *x, char *y);

int main()
{
    char str[] = "ABC";
    int arr[] = {1, 2, 3};
    int size = sizeof(arr) / sizeof(arr[0]);
    int n = strlen(str);
    permuteArr(arr, 0, size - 1);
    permute(str, 0, n - 1);
    return 0;
}


void swap(char *x, char *y)
{
    char temp = *x;
    *x = *y;
    *y = temp;
}


void swapNumbers(int *x, int *y)
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

void permuteArr(int *a, int l, int r)
{
    int i;
    if (l == r)
    {
        for (int j = 0; j <=r; j++)
        {
            printf("%d", *(a + j));
        }
        printf("\n");
    } else
    {
        for (i = l; i <= r; i++)
        {
            swapNumbers((a + l), (a + i));
            permuteArr(a, l + 1, r);
            swapNumbers((a + l), (a + i)); //backtrack
        }
    }
}

void permute(char *a, int l, int r)
{
    int i;
    if (l == r)
        printf("%s\n", a);
    else
    {
        for (i = l; i <= r; i++)
        {
            swap((a + l), (a + i));
            permute(a, l + 1, r);
            swap((a + l), (a + i)); //backtrack
        }
    }
}

int length(char *s)
{
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}