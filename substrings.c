//
// Created by maor on 01/11/2020.
//


#include <stdio.h>
#include <string.h>

int FindMaxSum(int arr[], int n);

void print_substrings(char str[], int n);

int main() {
    char s[] = "Geeky";
    print_substrings(s, strlen(s));

    int arr[] = {5, 5, 10, 100, 10, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("%d n", FindMaxSum(arr, n));
    return 0;
}


void print_substrings(char str[], int n) {
    for (int i = 0; i < n; ++i)
    {
        char temp[n - i + 1];
        int tempindex = 0;
        for (int j = i; j < n; j++)
        {
            temp[tempindex++] = str[j];
            temp[tempindex] = '\0';
            printf("%s\n", temp);
        }
    }
}


int FindMaxSum(int arr[], int n) {
    int incl = arr[0];
    int excl = 0;
    int excl_new;
    int i;

    for (i = 1; i < n; i++)
    {
        /* current max excluding i */
        excl_new = (incl > excl) ? incl : excl;

        /* current max including i */
        incl = excl + arr[i];
        excl = excl_new;
    }

    /* return max of incl and excl */
    return ((incl > excl) ? incl : excl);
}