#include <math.h>
#include <string.h>
#include <stdio.h>


#define HEIGHT 50
#define WIDTH 50

void
drawCircle(unsigned char pgmImage[][WIDTH], int height, int centerX, int centerY, int radius, unsigned char grayLevel)
{

    for (int rowIndex = centerY; rowIndex < HEIGHT; rowIndex++)
    {
        for (int colIndex = centerX; colIndex < WIDTH; colIndex++)
        {
            if ((pow(1.0 * (colIndex - centerX), 2)) + (pow(1.0 * (rowIndex - centerY), 2)) <= pow(1.0 * radius, 2))
            {
                pgmImage[rowIndex][colIndex] = (grayLevel);
            }
        }
    }
    for (int rowIndex = 0; rowIndex < centerY; rowIndex++)
    {
        for (int colIndex = 0; colIndex < centerX; colIndex++)
        {
            if ((pow(1.0 * (colIndex - centerX), 2)) + (pow(1.0 * (rowIndex - centerY), 2)) <= pow(1.0 * radius, 2))
            {
                pgmImage[rowIndex][colIndex] = (grayLevel);
            }
        }
    }
    for (int rowIndex = 0; rowIndex < centerY; rowIndex++)
    {
        for (int colIndex = centerX; colIndex < WIDTH; colIndex++)
        {
            if ((pow(1.0 * (colIndex - centerX), 2)) + (pow(1.0 * (rowIndex - centerY), 2)) <= pow(1.0 * radius, 2))
            {
                pgmImage[rowIndex][colIndex] = (grayLevel);
            }
        }
    }
    for (int rowIndex = centerY; rowIndex < HEIGHT; rowIndex++)
    {
        for (int colIndex = 0; colIndex < centerX; colIndex++)
        {
            if ((pow(1.0 * (colIndex - centerX), 2)) + (pow(1.0 * (rowIndex - centerY), 2)) <= pow(1.0 * radius, 2))
            {
                pgmImage[rowIndex][colIndex] = (grayLevel);
            }
        }
    }
}

int min(int a, int b)
{
    if (b > a)
    {
        return a;
    } else
    {
        return b;
    }
}

int main(void)
{
    char pgmImage[HEIGHT][WIDTH] = {{0}};
    int centerY = HEIGHT / 2;
    int centerX = WIDTH / 2;
    int radius = min(centerX, centerY) - 1;

    drawCircle(pgmImage, HEIGHT, centerX, centerY, radius, 1);
    for (int r = 0; r < HEIGHT; r++)
    {
        for (int c = 0; c < WIDTH; c++)
        {
            char o = (pgmImage[r][c] != 0) ? 'X' : '-';
            printf("%c",o);
        }
        printf("\n");
    }
    return 0;
}