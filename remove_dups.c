#include <stdio.h>
#include <string.h>

//
// Created by maor on 02/11/2020.
//
void removeDuplicate(char S[]);

int main()
{
    char str[] = "112233445511";
    int arr[] = {1, 2, 2, 2, 3, 4};
    removeDuplicate(str);
    printf("%s\n", str);
    return 0;
}

void removeDuplicate(char S[])
{
    int n = strlen(S);

    // We don't need to do anything for
    // empty or single character string.
    if (n < 2)
        return;

    // j is used to store index is result
    // string (or index of current distinct
    // character)
    int j = 0;

    // Traversing string
    for (int i = 1; i < n; i++)
    {
        // If current character S[i]
        // is different from S[j]
        if (S[j] != S[i])
        {
            j++;
            S[j] = S[i];
        }
    }

    // Putting string termination
    // character.
    j++;
    S[j] = '\0';
}
