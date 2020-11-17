#include <stdio.h>

//
// Created by maor on 02/11/2020.
//
int sum(int matrix[3][3]);

int memo(int matrix[3][3], int memo[3][3], int m, int n, int x, int y);

int max(int x, int y);

int main()
{

    int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };

    int n = sizeof(matrix)/sizeof(matrix[0]);
    int m = sizeof(matrix[0])/sizeof(matrix[0][0]);

    printf("%d",sum(matrix));
    return 0;
}

int sum(int matrix[3][3])
{
    int m = 3;
    int n = 3;
    int memory[][3] = {{0,  0, 0},
                  {0, 0, 0},
                  {0,  0, 0}};

    return memo(matrix, memory, m - 1, n - 1, 0, 0);


}

int memo(int matrix[3][3], int memory[3][3], int m, int n, int x, int y)
{
    if (x == m && y == n)
        return matrix[x][y];
    if (x > m || y > n)
        return 0;
    else
    {
        if (memory[x][y] != 0)
            return memory[x][y];


        memory[x][y] = matrix[x][y] + max(memo(matrix,memory,m,n,x+1,y+1),memo(matrix,memory,m,n,x+1,y));
        return memory[x][y];
    }

}

int max(int x, int y)
{
    return (x >= y ? x : y);
}