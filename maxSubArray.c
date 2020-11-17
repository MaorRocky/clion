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


int main()
{
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3};
    int n = sizeof(a) / sizeof(a[0]);
    int max_sum = maxSubArraySum(a, n);
    printf("%d",max_sum);
    return 0;
}


