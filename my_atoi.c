//
// Created by maor on 10/11/2020.
//

// A C program for
// implementation of atoi
#include <stdio.h>

// A simple atoi() function
int myAtoi(char *str)
{
    // Initialize result
    int res = 0;

    // Initialize sign as positive
    int sign = 1;

    // Initialize index of first digit
    int i = 0;

    // If number is negative,
    // then update sign
    if (str[0] == '-')
    {
        sign = -1;

        // Also update index of first digit
        i++;
    }

    // Iterate through all digits
    // and update the result
    for (; str[i] != '\0'; ++i)
        res = res * 10 + str[i] - '0';

    // Return result with sign
    return sign * res;
}

// Driver code
int main()
{
    char str[] = "-123";

    // Function call
    int val = myAtoi(str);
    printf("%d ", val);
    return 0;
}
