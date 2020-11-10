//
// Created by maor on 10/11/2020.
//


#include <memory.h>
#include <stdio.h>

# define NO_OF_CHARS 256

void check_perms(char *str1, char *str2);

int main()
{
    check_perms("maor", "mmmo");
    return 0;
}

void check_perms(char *str1, char *str2)
{
    int len = strlen(str1);
    if (len != strlen(str2))
    {
        printf("false");
    }
    int letters[NO_OF_CHARS];
    for (int i = 0; i < len; ++i)
    {
        letters[str1[i]]++;
    }
    for (int i = 0; i < len; ++i)
    {
        letters[str2[i]]--;
        if (letters[str2[i]] < 0)
        {
            printf("break false");
            return;
        }
    }

    printf("true");


}