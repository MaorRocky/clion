#include <limits.h>
#include <stdio.h>

int maxSubArraySum(int a[], int size);

int maxSubArraySum(int a[], int size)
{

    int max = a[0];
    int curr_sum = max;
    for (int i = 1; i < size; ++i)
    {
        curr_sum = curr_sum + a[i] > a[i] ? curr_sum + a[i] : a[i];
        max = curr_sum > max ? curr_sum : max;
    }
    return max;


}

int maxSubArrayIndex(int a[], int size)
{
    int max_so_far = INT_MIN, max_ending_here = 0,
            start =0, end = 0, s=0;

    for (int i=0; i< size; i++ )
    {
        max_ending_here += a[i];

        if (max_so_far < max_ending_here)
        {
            max_so_far = max_ending_here;
            start = s;
            end = i;
        }

        if (max_ending_here < 0)
        {
            max_ending_here = 0;
            s = i + 1;
        }
    }

    printf("%d %d\n",start,end);
    return max_so_far;


}


int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArrayIndex(a, n);
    printf("%d", max_sum);
    return 0;
}


