//
// Created by maor on 09/11/2020.
//
#include <stdio.h>
#include <stdint.h>
#include <memory.h>
#include <stdlib.h>
#include<string.h>

//char *reverse(char *str);
void reverse_string(char s[]);

void reverse_substring(char *left, char *right);

void my_itoa(int n, char s[]);

char *convert(int number, char *buff, int base);

int main() {
    char buff[4];

    my_itoa(-123, buff);
    printf("%s", buff);

    return 0;
}

/*const char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

char *convert(int number, char *buff, int base) {
    char *result = (buff == NULL || base > strlen(digits) || base < 2) ? NULL : buff;
    char sign = 0;


    if (number < 0)
    {
        sign = '-';

    }
    if (result != NULL)
    {
        do
        {
            *buff++ = digits[abs(number % (base))];
            number /= base;
        } while (number);
        if (sign) *buff++ = sign;
        if (!*result) *buff++ = '0';
        *buff = 0;
        reverse(result);
    }
    return result;
}

void reverse_substring(char *left, char *right) {
    while (left < --right)
    {
        char c = *right;
        *right = *left;
        *left++ = c;
    }
}

char *reverse(char *str) {
    char *end = str;
    while (*end)
    {
        end++;
    }
    reverse_substring(str, end);
    return str;
}*/

void reverse_string(char s[]) {
    char r[1000];
    int begin, end, count = 0;



    // Calculating string length

    while (s[count] != '\0')
        count++;

    end = count - 1;

    for (begin = 0; begin < count; begin++)
    {
        r[begin] = s[end];
        end--;
    }

    r[begin] = '\0';
    for (int i = 0; r[i] != '\0'; ++i)
    {
        s[i] = r[i];
    }


}

void my_itoa(int n, char s[]) {
    int i, sign;
    if ((sign = n) < 0)
        n = -n;
    i = 0;
    do
    {
        s[i++] = n % 10 + '0';

    } while ((n /= 10) > 0);
    if (sign < 0)
        s[i++] = '-';
    s[i] = '\0';
    reverse_string(s);
}