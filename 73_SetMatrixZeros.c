#include<stdio.h>
#include<stdlib.h>

void Display(int (*matrix)[50])
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 4; j++)
        {
            printf("%d\t",matrix[i][j]);
        }
        printf("\n");
    }
}

void setZeroes(int (*matrix)[50], int matrixSize, int* matrixColSize) 
{
    int i = 0,j = 0,k = 0;
    int row = matrixSize,col = *matrixColSize;
    
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(matrix[i][j] == 0)
            {
                for(k = 0; k < row; k++)
                {
                    if(matrix[k][j] != 0)
                    {
                        matrix[k][j] = -99999;
                    }
                }
                for(k = 0; k < col; k++)
                {
                    if(matrix[i][k] != 0)
                    {
                        matrix[i][k] = -99999;
                    }
                }
            }
        }
    }
    for(i = 0; i < row; i++)
    {
        for(j = 0; j < col; j++)
        {
            if(matrix[i][j] == -99999)
            {
                matrix[i][j] = 0;
            }
        }
    }
}

int main()
{
    int arr[50][50] = {{0,1,2,0},{3,4,5,2},{1,3,1,5}};
    
    int row = 3,col = 4;
    printf("Matrix before \n");
    Display(arr);
    setZeroes(arr,row,&col);
    printf("Matrix after \n");
    Display(arr);

    return 0;
}