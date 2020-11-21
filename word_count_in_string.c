#include <stdio.h>
#include "stdbool.h"


bool is_space(char s)
{
    return s == ' ';
}


int count_w(char *s)
{
    int count = 0;
    char *end;
    for (char *start = s; *start; start = end)
    {
        while (*start && is_space(*start))
        {
            start++;
        }
        end = start;
        while (*end && !is_space(*end))
        {
            end++;
        }
        count++;


    }
    return count;


}

int unique(char *s)
{
    char word[101][40];
    for (int count = 0; count < 101; count++)
    {
        sprintf(word[count], "%39s", s);

    }
}


int main(void)
{

    char s[] = "   Lorem   ipsum dolor sit amet, consectetur adipiscing elit. Ut eleifend in enim eu viverra. Fusce accumsan rhoncus rhoncus. Cras sed ex sit amet augue suscipit vestibulum posuere eu lectus. Vestibulum";
    printf("%d\n", count_w(s));
    return 0;
}