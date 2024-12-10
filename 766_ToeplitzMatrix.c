#include<stdio.h>
#include<stdbool.h>

bool isToeplitzMatrix(int (*matrix)[10], int matrixSize, int* matrixColSize) 
{
    bool flag = true;

    for(int i = 0; i < matrixSize-1; i++)
    {
        for(int j = 1; j < *matrixColSize; j++)
        {
            if(matrix[i][j-1] != matrix[i+1][j])
            {
                flag = false;
                break;
            }
        }
    }
    return flag;
}

int main()
{
    int arr[][10] = {{1,2},{2,2}};
    int col = 2;
    printf("%d\n",isToeplitzMatrix(arr,2,&col));

    return 0;
}