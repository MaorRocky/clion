//
// Created by maor on 02/11/2020.
//


#include <stdio.h>
#include <string.h>

void permute(char *a, int l, int r);

int length(char *s);

void swap(char *x, char *y);

int main() {
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n - 1);
    return 0;
}


void swap(char *x, char *y) {
    char temp = *x;
    *x = *y;
    *y = temp;
}


void permute(char *a, int l, int r) {
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

int length(char *s) {
    int i;
    for (i = 0; s[i] != '\0'; ++i);
    return i;
}