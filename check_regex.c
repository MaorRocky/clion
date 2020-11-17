//
// Created by maor on 17/11/2020.
//

#include <stdio.h>
#include <string.h>


int compareHelper(char *s, char *regex, int star);

int compareStrings(char *s, char *r);

int main()
{
    printf("%d\n", compareStrings("aaaacbbb", "a*b"));
    printf("%d\n", compareStrings("aaaabccccccccb", "a*b*c"));
    return 0;

}

//aaaaacbbb
//a*b

int compareStrings(char *s, char *r)
{
    return compareHelper(s, r, 0);

}

int compareHelper(char *s, char *regex, int star)
{
    if (*s == '\0' && *regex == '\0')
    {
        return 1;
    } else if (*regex == '*')
    {
        regex++;
        return compareHelper(s, regex, 1); // star is seen hence will be set to true.
    } else
    {
        if (!star)
        {
            if (*s != *regex)
            { // star was not seen and they differ in char
                return 0;
            } else
            {
                s++;
                regex++;
                return compareHelper(s, regex, star);
            }

        } else
        {
            while (*s && *s != *regex)
            {
                s++;
            }
            if (*s == '\0') return 0;
            else
            {
                s++;
                return compareHelper(s, regex + 1, 0) | compareHelper(s, regex, 1);
            }
        }
    }
}

