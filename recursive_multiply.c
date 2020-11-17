#include <stdio.h>

int helper3(int smaller, int bigger);

int minProduct3(int a, int b);

int minProduct3(int a, int b)
{
    int bigger = a < b ? b : a;
    int smaller = a < b ? a : b;
    return helper3(smaller, bigger);
}

int helper3(int smaller, int bigger)
{
    if (smaller == 0)
    {
        return 0;
    } else if (smaller == 1)
    {
        return bigger;
    }
    int s = smaller >> 1;
    int halfProd = helper3(s, bigger);
    if (smaller % 2 == 0)
    {
        return halfProd + halfProd;
    } else
    {
        return halfProd + halfProd + bigger;
    }
}

int main()
{

    printf("%d", minProduct3(4, 2));
    return 0;
}