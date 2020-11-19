#include <stdio.h>
#include <stdbool.h>

//
// Created by maor on 09/11/2020.
//
char *itoa(int num, char *str, int base);

void reverse(char str[], int length);

void swap(char *left, char *right);

int main()
{
    char str[100];
    printf("%s", itoa(1567, str, 10));

    return 0;
}

void reverse(char str[], int length)
{
    int start = 0;
    int end = length - 1;
    while (start < end)
    {
        swap((str + start), (str + end));
        start++;
        end--;
    }
}

// Implementation of itoa()
char *itoa(int num, char *str, int base)
{
    int i = 0;
    bool isNegative = false;

    /* Handle 0 explicitely, otherwise empty string is printed for 0 */
    if (num == 0)
    {
        str[i++] = '0';
        str[i] = '\0';
        return str;
    }

    // In standard itoa(), negative numbers are handled only with
    // base 10. Otherwise numbers are considered unsigned.
    if (num < 0)
    {
        isNegative = true;
        num = -num;
    }

    // Process individual digits
    while (num != 0)
    {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num = num / base;
    }

    // If number is negative, append '-'
    if (isNegative)
        str[i++] = '-';

    str[i] = '\0'; // Append string terminator

    // Reverse the string
    reverse(str, i);

    return str;
}

void swap(char *left, char *right)
{
    char temp = *left;
    *left = *right;
    *right = temp;
}