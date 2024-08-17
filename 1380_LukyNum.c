#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* luckyNumbers (int (*matrix)[50], int matrixSize, int matrixColSize) 
{
    int *arr = (int*)malloc(sizeof(int)*10);
    int Min = 0,k = 0;
    bool flag = true;
    for(int i = 0; i < matrixSize; i++)
    {
        Min = matrix[i][0];
        flag = true;
        for(int j = 0; j < matrixSize; j++)
        {
            if(Min > matrix[i][j])
            {
                Min = matrix[i][j];
                k = j;
            }
        }
        for(int i = 0; i < matrixSize; i++)
        {
            if(Min < matrix[i][k])
            {
                flag = false;
                Min = -1;
                break;
            }
        }
        if(flag == true) break;
    }
    if(Min != -1)
    {
        arr[0] = Min;
    }
    return arr;
}

int main()
{
    int arr[50][50] = {{7,8},{1,2}};
    int *ret = luckyNumbers(arr,2,2);

    printf("%d\n",*ret);

    return 0;
}