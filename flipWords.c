void reverse_substring(char *left, char *right) {
    while (left < --right)
    {
        char c = *right;
        *right = *left;
        *left++ = c;
    }
}

#include <ctype.h>
/* reverse individual words in string */
/* word boundaries determined by isspace() */
char *reverse_words(char *name) {
    char *end;
    for (char *start = name; *start; start = end)
    {
        while (*start && isspace(*start))
        {
            ++start;
        }
        end = start;
        while (*end && !isspace(*end))
        {
            ++end;
        }
        reverse_substring(start, end);
    }

    return name;
}

#include <stdio.h>

int main(void) {
    char s[] = " AB BBC QQ ";
    printf("%s", reverse_words(s));
}