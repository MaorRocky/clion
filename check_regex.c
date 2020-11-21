// A C program to match wild card characters 
#include <stdio.h>
#include <stdbool.h>

// The main function that checks if two given strings 
// match. The glob string may contain wildcard characters 
bool match(char *glob, char *second)
{
    // If we reach at the end of both strings, we are done
    if (*glob == '\0' && *second == '\0')
        return true;

    // Make sure that the characters after '*' are present
    // in second string. This function assumes that the glob
    // string will not contain two consecutive '*'
    if (*glob == '*' && *(glob + 1) != '\0' && *second == '\0')
        return false;

    // If the glob string contains '?', or current characters
    // of both strings match
    if (*glob == *second)
    {
        return match(glob + 1, second + 1);
    }

    // If there is *, then there are two possibilities
    // a) We consider current character of second string
    // b) We ignore current character of second string.
    if (*glob == '*')
        return match(glob + 1, second) || match(glob, second + 1);
    return false;
}

// A function to run test cases 
void test(char *glob, char *second)
{ match(glob, second) ? puts("Yes") : puts("No"); }

// Driver program to test above functions 
int main()
{
    test("a*b", "aaaaaacccccbbbbb"); // yes
    test("a*b*c", "aaaabcccccccccb"); // no
    test("g*ks", "geeks"); // Yes
    test("g*k", "gee"); // No because 'k' is not in second
    test("*pqrs", "pqrst"); // No because 't' is not in glob
    test("abc*bcd", "abcdhghgbcd"); // Yes
    // instances of 'c'
    test("*c*d", "abcd"); // Yes
    return 0;
} 
