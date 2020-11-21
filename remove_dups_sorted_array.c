/* C program to remove duplicate elements in an array */
#include<stdio.h>

int removeDuplicates(int arr[], int n)
{
    // Return, if array is empty
    // or contains a single element
    if (n == 0 || n == 1)
        return n;

    int temp[n];

    // Start traversing elements
    int j = 0;
    for (int i = 0; i < n - 1; i++)

        // If current element is not equal
        // to next element then store that
        // current element
        if (arr[i] != arr[i + 1])
            temp[j++] = arr[i];

    // Store the last element as whether
    // it is unique or repeated, it hasn't
    // stored previously
    temp[j++] = arr[n - 1];

    // Modify original array
    for (int i = 0; i < j; i++)
        arr[i] = temp[i];

    return j;
}

int removeDuplicates_unsorted(int arr[], int size)
{
    int i, j, k = 0;
    arr[k] = arr[0];

    for (i = 1; i < size; i++)
    {
        for (j = i + 1; j < size; j++)
        {
            if (arr[j] == arr[i])
                arr[j] = arr[0];
        }
        if (arr[i] != arr[0])
        {
            k++;
            arr[k] = arr[i];

        }
    }

    //size = k+1;
    return k + 1;
}


int main()
{
    int n = 6;
    int arr[] = {1, 2, 2, 3, 3, 4,};


    n = removeDuplicates(arr, n);


    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");

    int arr2[] = {12, 65, 12, 65, 20, 12, 20, 17, 17, 28, 85};

    int size = sizeof(arr2) / sizeof(arr2[0]);

    size = removeDuplicates_unsorted(arr2, size);

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr2[i]);
    }

    return 0;
}