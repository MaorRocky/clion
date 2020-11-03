// C program to sort an array with 0, 1 and 2 
// in a single pass 
#include <stdio.h>

/* Function to swap *a and *b */
void swap(int* a, int* b);

// Sort the input array, the array is assumed to 
// have values in {0, 1, 2} 
void sort012(int a[], int arr_size)
{
    int p0 = 0;
    int p2 = arr_size - 1;
    int p1 = 0;

    while (p1 <= p2) {
        switch (a[p1]) {
            case 0:
                swap(&a[p0++], &a[p1++]);
                break;
            case 1:
                p1++;
                break;
            case 2:
                swap(&a[p1], &a[p2--]);
                break;
        }
    }
}

/* UTILITY FUNCTIONS */
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Utility function to print array arr[] */
void printArray(int arr[], int arr_size)
{
    int i;
    for (i = 0; i < arr_size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

/* driver program to test */
int main()
{
    int arr[] = { 0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1 };
    int arr_size = sizeof(arr) / sizeof(arr[0]);

    sort012(arr, arr_size);

    printf("array after segregation\n");
    printArray(arr, arr_size);

    getchar();
    return 0;
} 
