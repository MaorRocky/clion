#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>

bool is_space(char s)
{
    return s == ' ';
}

void reverse_substring(char *left, char *right)
{
    while (left < --right)
    {
        char c = *right;
        *right = *left;
        *left++ = c;
    }
}

/* reverse individual words in string */
/* word boundaries determined by isspace() */
char *reverse_words(char *name)
{
    char *end;
    for (char *start = name; *start; start = end)
    {
        while (*start && is_space(*start))
        {
            ++start;
        }
        end = start;
        while (*end && !is_space(*end))
        {
            ++end;
        }
        reverse_substring(start, end);
    }

    return name;
}


int main(void)
{
    char s[] = " AB BBC QQ ";
    printf("%s", reverse_words(s));
}