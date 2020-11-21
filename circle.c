#include <stdio.h>
#include <math.h>
#include <stdlib.h>


#define WIDTH 50
#define HEIGHT 50
#define X WIDTH/2
#define Y HEIGHT/2
#define XMAX WIDTH-X-1
#define XMIN -(WIDTH-X)
#define YMAX HEIGHT-Y
#define YMIN -(HEIGHT-Y)+1

char grid[HEIGHT][WIDTH];

int circle(int x, int y, int radius);
int plot(int x, int y);
void init_grid(void);
void show_grid(void);

/* Plot a circle */
int circle(int x, int y, int radius)
{
    float xpos,ypos,radsqr,xsqr;

    for(xpos=x-radius;xpos<=x+radius;xpos+=0.1)
    {
        radsqr = pow(radius,2);
        xsqr = pow(xpos,2);
        ypos = sqrt(abs(radsqr - xsqr));
        plot(rintf(xpos),rintf(ypos));
        plot(rintf(xpos),rintf(-ypos));
    }

    return(1);
}


/* Set "pixel" at specific coordinates */
int plot(int x, int y)
{
    if (x > XMAX || x < XMIN || y > YMAX || y < YMIN)
        return (-1);

    grid[Y - y][X + x] = '*';
    return (1);
}

/* Initialize grid */
void init_grid(void)
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
        for (x = 0; x < WIDTH; x++)
            grid[y][x] = ' ';
    /* draw the axis */
    for (y = 0; y < HEIGHT; y++)
        grid[y][X] = '|';
    for (x = 0; x < WIDTH; x++)
        grid[Y][x] = '-';
    grid[Y][X] = '+';
}

/* display grid */
void show_grid(void)
{
    int x, y;

    for (y = 0; y < HEIGHT; y++)
    {
        for (x = 0; x < WIDTH; x++)
            putchar(grid[y][x]);
        putchar('\n');
    }
}


void my_circle(int a, int b, int r)
{

    int width = 50;
    int height = 50;
    int my_x = width / 2;
    int my_y = height / 2;
    int xmax = width - my_x - 1;
    int xmin = -(width - my_x);
    int ymax = height - my_y;
    int ymin = -(height - my_y) + 1;
    double epsilion = 2.1;
    char matrix[height][width];

    for (int x = 0; x < width; ++x)
    {
        for (int y = 0; y < height; ++y)
        {
            matrix[x][y] = '.';
        }
    }

    for (int y = 0; y < height; y++)
        matrix[y][my_x] = '|';
    for (int x = 0; x < width; x++)
        matrix[my_y][x] = '-';
    matrix[Y][X] = '+';

    for (int x = 0; x < height; ++x)
    {
        for (int y = 0; y < width; ++y)
        {

            int xs = pow(x - a, 2);
            int ys = pow(y - b, 2);
            int rs = pow(r, 2);
            if (abs(xs + ys - rs) < pow(epsilion, 2))
                matrix[my_y - y][x + my_x] = '#';
        }
    }

    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            printf("%c ", matrix[i][j]);
        }
        printf("\n");
    }
}


int main()
{
   /* init_grid();
    circle(0   , 0, 4);
    show_grid();*/
    int width = 50, height = 50;
    int a = 25, b = 25;
    int r = 5;
    double epsilon = 2.2;
    char mat[width][height];
    for (int i = 0; i < width; ++i)
    {
        for (int j = 0; j < height; ++j)
        {
            mat[i][j] = '.';
        }
    }
    for (int y = 0; y < height; ++y)
    {
        for (int x = 0; x < width; ++x)
        {
            if (abs(pow(x - a, 2) + pow(y - b, 2) - pow(r, 2)) < pow(epsilon, 2))
            {
                mat[y][x] = '1';
            }
        }
    }
    for (int i = 0; i < width; i++)
    {
        for (int j = 0; j < height; j++)
        {
            printf("%c ", mat[i][j]);
        }
        printf("\n");
    }
//    my_circle(0, 5, 5);

    return (0);
}