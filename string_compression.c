#include<stdio.h>

char *StrCompress(char myStr[])
{
    char *s = myStr;
    char *r, *p;
    int count, i;
    char count_arr[50];
    while (*s)
    {
        /*initially only 1 character of a kind is present*/
        count = 1;

        /*we check whether current character matches the next one*/
        while (*s && *s == *(s + 1))
        {
            /*if yes,then increase the count due to the match 
            and increment the string pointer to next */
            count++;
            s++;
        }

        if (count > 1) /*if more than one character of a kind is present*/
        {
            /*assign the value of count to second occurence of a particular character*/
            sprintf(count_arr, "%d", count);
            for (int j = 0; *(count_arr + j); ++j, s++)
            {
                *(s - count + 2) = count_arr[j];
            }
//            *(s - count + 2) = count + '0';

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


#include <stdlib.h>
#include <string.h>

#define MAX_RLEN 50

/* Returns the Run Length Encoded string for the
   source string src */
char *encode(char *src)
{
    int counter;
    char count[MAX_RLEN];
    int len = strlen(src);

    /* If all characters in the source string are different,
    then size of destination string would be twice of input string.
    For example if the src is "abcd", then dest would be "a1b1c1d1"
    For other inputs, size would be less than twice.  */
    char *dest = (char *) malloc(sizeof(char) * (len * 2 + 1));

    int i, j = 0, k;

    /* traverse the input string one by one */
    for (i = 0; i < len; i++)
    {

        /* Copy the first occurrence of the new character */
        dest[j++] = src[i];

        /* Count the number of occurrences of the new character */
        counter = 1;
        while (i + 1 < len && src[i] == src[i + 1])
        {
            counter++;
            i++;
        }

        /* Store counter in a character array count[] */
        sprintf(count, "%d", counter);

        /* Copy the count[] to destination */
        for (k = 0; *(count + k); k++, j++)
        {
            dest[j] = count[k];
        }
    }

    /*terminate the destination string */
    dest[j] = '\0';
    return dest;
}

char *rev_encode(char *src)
{
    int counter;
    char count[MAX_RLEN];
    int len = strlen(src);
    char temp_char;
    char *dest = (char *) malloc(sizeof(char) * (len * 2 + 1));


    int i, j = 0, k;

    /* traverse the input string one by one */
    for (i = 0; i < len; i++)
    {

        /* Copy the first occurrence of the new character */
        temp_char = src[i];

        /* Count the number of occurrences of the new character */
        counter = 1;
        while (i + 1 < len && src[i] == src[i + 1])
        {
            counter++;
            i++;
        }

        /* Store counter in a character array count[] */
        sprintf(count, "%d", counter);

        /* Copy the count[] to destination */
        for (k = 0; *(count + k); k++, j++)
        {
            dest[j] = count[k];
        }
        dest[j++] = temp_char;
    }
    dest[j] = '\0';
    return dest;


}

int main()
{
//    char myStr[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBCCCCCCDDDEFGHHIJJ";

//    printf("Compressed String is : %s\n", StrCompress(myStr));
    char str[] = "AAAAAAAAAAAAAAAAAAAAAAAAAAAAAABBBCCCCCCDDDEFGHHIJJ";
    char rev_str[] = "aaabbbcd";
    char *res = encode(str);
    char *rev = rev_encode(rev_str);
    printf("%s\n", res);
    printf("%s", rev);
    free(res);
    free(rev);

    return 0;
}