#include <stdio.h>

#define N 3


int max(int x, int y)
{
    return (x >= y ? x : y);
}

int memo(int matrix[N][N], int memory[N][N], int m, int n, int x, int y)
{
    if (x == m && y == n)
        return matrix[x][y];
    if (x < m || y < n)
        return 0;
    else
    {
        if (memory[x][y] != 0)
            return memory[x][y];


        memory[x][y] =
                matrix[x][y] + max(memo(matrix, memory, m, n, x - 1, y - 1),
                                   memo(matrix, memory, m, n, x - 1, y));
        return memory[x][y];
    }

}

int sum(int matrix[N][N])
{

    int memory[N][N];
    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < N; ++j)
        {
            memory[i][j] = 0;
        }
    }

    return memo(matrix, memory, 0, 0, N-1, N-1);


}


int main()
{

    int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    int n = sizeof(matrix) / sizeof(matrix[0]);
    int m = sizeof(matrix[0]) / sizeof(matrix[0][0]);

    printf("%d", sum(matrix));
    return 0;
}