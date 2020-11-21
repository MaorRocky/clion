
#include <stdio.h>

#define N 3

void displayMatrix(int mat[N][N]);

// An Inplace function to
// rotate a N x N matrix
// by 90 degrees in
// anti-clockwise direction
void rotateMatrixClockWise(int mat[][N])
{
    // Traverse each cycle
    for (int x = 0; x < N / 2; x++)
    {
        for (int y = x; y < N - x - 1; y++)
        {

            // Swap elements of emmattch cycle
            // in clockwise direction
            int temp = mat[x][y];
            mat[x][y] = mat[N - 1 - y][x];
            mat[N - 1 - y][x] = mat[N - 1 - x][N - 1 - y];
            mat[N - 1 - x][N - 1 - y] = mat[y][N - 1 - x];
            mat[y][N - 1 - x] = temp;
        }
    }
}


// Function to print the matrix
void displayMatrix(int mat[N][N])
{
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
            printf("%2d ", mat[i][j]);

        printf("\n");
    }
    printf("\n");
}

void trnspose(int mat[N][N])
{
    int trans[N][N];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            trans[j][i] = mat[i][j];
        }
    }

    displayMatrix(trans);
}

/* Driver program to test above functions */
int main()
{
    // Test Case 1
    /*int mat[N][N] = {
            {1,  2,  3,  4},
            {5,  6,  7,  8},
            {9,  10, 11, 12},
            {13, 14, 15, 16}
    };
*/
    // Tese Case 2
    int mat[N][N] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    trnspose(mat);

    // Tese Case 3
    /*int mat[N][N] = {
                    {1, 2},
                    {4, 5}
                };*/

    // displayMatrix(mat);

    rotateMatrixClockWise(mat);

    // Print rotated matrix
    displayMatrix(mat);

    return 0;
}
