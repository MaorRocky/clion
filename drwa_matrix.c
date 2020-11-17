#include <stdio.h>

int main()
{
    float x = 0, y = 0, ypos = 0, xpos = 0, radius = 3, rsqrd = 0, rcheck = 0;
    int matsize = 0, i, j;


    printf("Value of radius:");
    scanf("%f", &radius);
    printf("Position of circle on the x axis:");
    scanf("%f", &xpos);
    printf("Position of circle on the y axis:");
    scanf("%f", &ypos);
    printf("Resolution:");
    scanf("%d", &matsize);
    printf("\n");


    rsqrd = radius * radius; //rsqrd is equal to radius squared.
    x = -1 * (matsize / 2);
    //with this I make sure that the x and y values start from the top right corner of the matrix, so that each x, y value corresponds to the correct cell position (i, j)
    y = matsize / 2;
    int mat[10][10];


    for (i = 0; i < matsize; i++)
    {
        for (j = 0; j < matsize; j++)
        {
            rcheck = ((y - ypos) * (y - ypos)) + ((x - xpos) * (x -
                                                                xpos)); // calculating the equation of the circle with the x and y values taking the offset into account
            if (rcheck <= rsqrd)
            {
                mat[i][j] = 1;
            } else
            {
                mat[i][j] = 0;
            }
            x = x + 1; //stepping the values of x and y so they stay with the corresponding cell
        }
        y = y - 1;
        x -= matsize;   // <-- Reset x to start of row
    }


    for (i = 0; i < matsize; i++) // displaying the matrix
    {
        for (j = 0; j < matsize; j++)
        {
            printf("%d ", mat[i][j]);
        }
        printf("\n");
    }


    return 0;
}