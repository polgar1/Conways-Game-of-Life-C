#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void setup(int grid[70][70]);
void print(int grid[70][70]);
void nextGeneration(int grid[70][70]);

int main(void)
{
    srand(time(NULL));
    int grid[70][70];
    setup(grid);
    print(grid);
    
    while (1)
    {
        char* command = malloc(sizeof(char)*5);
        scanf("%s", command);
        if (strcmp(command, "exit") == 0)
        {
            break;
        }
        else if (strcmp(command, "next") == 0)
        {
            nextGeneration(grid);
            printf("\033[H\033[J");  // ANSI escape code to clear the console
            print(grid);
        }
        free(command);
    }
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

void nextGeneration(int grid[70][70])
{
    int tempGrid[70][70];
    for (int i = 0; i < 70; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            int numOfNeighbors = 0;
            if (i > 0 && j > 0 && grid[i-1][j-1] == 1) numOfNeighbors++;
            if (i > 0 && grid[i-1][j] == 1) numOfNeighbors++;
            if (i > 0 && j < 69 && grid[i-1][j+1] == 1) numOfNeighbors++;
            if (j > 0 && grid[i][j-1] == 1) numOfNeighbors++;
            if (j < 69 && grid[i][j+1] == 1) numOfNeighbors++;
            if (i < 69 && j > 0 && grid[i+1][j-1] == 1) numOfNeighbors++;
            if (i < 69 && grid[i+1][j] == 1) numOfNeighbors++;
            if (i < 69 && j < 69 && grid[i+1][j+1] == 1) numOfNeighbors++;

            if (grid[i][j] == 1)
            {
                if (numOfNeighbors == 2 || numOfNeighbors == 3)
                {
                    tempGrid[i][j] = 1;
                }
                else
                {
                    tempGrid[i][j] = 0;
                }
            }
            else if (grid[i][j] == 0)
            {
                if (numOfNeighbors == 3)
                {
                    tempGrid[i][j] = 1;
                }
                else
                {
                    tempGrid[i][j] = 0;
                }
            }
            
        }
    }
    
    for (int i = 0; i < 70; i++)
    {
        for (int j = 0; j < 70; j++)
        {
            grid[i][j] = tempGrid[i][j];
        }
    }

}