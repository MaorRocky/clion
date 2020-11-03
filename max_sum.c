//
// Created by maor on 02/11/2020.
//
int sum(int matrix[3][3]);

int memo(int matrix[3][3], int memo[3][3], int m, int n, int x, int y);

int max(int x, int y);

int main() {

    int matrix[3][3] = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9}
    };


    return 0;
}

int sum(int matrix[3][3]) {
    int m = 3;
    int n = 3;
    int memory[m][n] = {{0,0,0},{0,0,0},{0,0,0}};
    return memo(matrix, memory, m - 1, n - 1, 0, 0);


}

int memo(int matrix[3][3], int memo[3][3], int m, int n, int x, int y) {
    if (x == m && y == n)
        return matrix[x][y];
    if (x > m || y > n)
        return 0;
    else
    {
        if (memo[x][y] != 0)
            return memo[x][y];

        memo[x][y] = matrix[x][y] + max(memo(matrix, memo, m, n, x + 1, y + 1),
                                        memo(matrix, memo, m, n, x + 1, y));
        return memo[x][y];
    }

}

int max(int x, int y) {
    return (x >= y ? x : y);
}