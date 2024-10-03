#include <stdio.h>
#include <stdlib.h>
#include <string.h>


void setup(int grid[70][70]);
void print(int grid[70][70]);

int main(void)
{
    int grid[70][70];
    setup(grid);
    print(grid);
}

void setup(int grid[70][70])
{
    for (int i = 0; i < 70; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            grid[i][j] = rand() % 2;
        }

    }
}

void print(int grid[70][70])
{
    for (int i = 0; i < 70; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            printf("%i", grid[i][j]);
        }
        printf("\n");
    }
    return;
}