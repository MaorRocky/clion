//
// Created by maor on 20/11/2020.
//

#include <stdlib.h>

#include<stdio.h>

#define N 3

char mat[100][100];

void drawline(int x0, int y0, int x1, int y1)
{


    int dx, dy, p, x, y;

    dx = x1 - x0;
    dy = y1 - y0;

    x = x0;
    y = y0;

    p = 2 * dy - dx;

    while (x < x1)
    {
        if (p >= 0)
        {
//            putpixel(x, y, 7);
            mat[x][y] = '*';
            y = y + 1;
            p = p + 2 * dy - 2 * dx;
        } else
        {
//            putpixel(x, y, 7);
            mat[x][y] = '*';

            p = p + 2 * dy;
        }
        x = x + 1;
    }
}

void line(int x0, int y0, int x1, int y1)
{

    int dx = abs(x1 - x0), sx = x0 < x1 ? 1 : -1;
    int dy = abs(y1 - y0), sy = y0 < y1 ? 1 : -1;
    int err = (dx > dy ? dx : -dy) / 2, e2;

    for (;;)
    {
        mat[x0][y0] = '*';
        if (x0 == x1 && y0 == y1) break;
        e2 = err;
        if (e2 > -dx)
        {
            err -= dy;
            x0 += sx;
        }
        if (e2 < dy)
        {
            err += dx;
            y0 += sy;
        }
    }
}


void lineGfg(int x1, int y1, int x2, int y2)
{

    int dx = x2 - x1;
    int dy = y2 - y1;
    int m_new = 2 * dy;
    int slope_error_new = m_new - dx;
    for (int x = x1, y = y1; x <= x2; x++)
    {
        printf("(%d, %d)\n", x, y);
        mat[y][x] = '*';
        slope_error_new += m_new;

        // Slope error reached limit, time to
        // increment y and update slope error.
        if (slope_error_new >= 0)
        {
            y++;
            slope_error_new -= 2 * (x2 - x1);
        }
    }
}

int main(void)
{
    for (int i = 0; i < 100; ++i)
    {
//        printf("%d ", i);
        for (int j = 0; j < 100; ++j)
        {
            mat[i][j] = '.';
        }
    }

    lineGfg(1, 1, 11, 5);
    for (int i = 0; i < 100; ++i)
    {
        for (int j = 0; j < 100; ++j)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}