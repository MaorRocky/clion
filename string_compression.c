#include<stdio.h>

char* StrCompress(char myStr[])
{
    char *s = myStr;
    char *r, *p;
    int count, i;

    while (*s)
    {
        /*initially only 1 character of a kind is present*/
        count = 1;

        /*we check whether current character matches the next one*/
        while (*s && *s == *(s+1))
        {
            /*if yes,then increase the count due to the match 
            and increment the string pointer to next */
            count++;
            s++;
        }

        if (count > 1) /*if more than one character of a kind is present*/
        {
            /*assign the value of count to second occurence of a particular character*/
            *(s - count + 2) = count + '0';

            /*delete all other occurences except the first one and second one using array shift*/
            for (i = 0; i < count - 2; i++)
            {
                p = s + 1;
                r = s;

                while (*r)
                    *r++ = *p++;

                s--;
            }
        }
        s++;
    }

    return myStr;
}


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_RLEN 50

/* Returns the Run Length Encoded string for the
   source string src */
char* encode(char* src)
{
    int rLen;
    char count[MAX_RLEN];
    int len = strlen(src);

    /* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
    char* dest = (char*)malloc(sizeof(char) * (len * 2 + 1));

    int i, j = 0, k;

    /* traverse the input string one by one */
    for (i = 0; i < len; i++) {

        /* Copy the first occurrence of the new character */
        dest[j++] = src[i];

        /* Count the number of occurrences of the new character */
        rLen = 1;
        while (i + 1 < len && src[i] == src[i + 1]) {
            rLen++;
            i++;
        }

        /* Store rLen in a character array count[] */
        sprintf(count, "%d", rLen);

        /* Copy the count[] to destination */
        for (k = 0; *(count + k); k++, j++) {
            dest[j] = count[k];
        }
    }

    /*terminate the destination string */
    dest[j] = '\0';
    return dest;
}

int main()
{
    char myStr[] = "AAAABBBCCCCCCDDDEFGHHIJJ";

    printf("Compressed String is : %s\n", StrCompress(myStr));
    char str[] = "AAAABBBCCCCCCDDDEFGHHIJJ";
    char* res = encode(str);
    printf("%s", res);

    return 0;
}