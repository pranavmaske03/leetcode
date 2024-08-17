#include<stdlib.h>
#include<stdio.h>
#include<stdbool.h>

int** init(int iRow,int iCol)
{
    int** arr = NULL;
    arr = (int **) malloc(10 * sizeof(int*));
    for (int i = 0; i < iRow; i++) 
    {
        arr[i] = (int*) malloc(iRow * sizeof(int));
        for (int j = 0; j < iCol; j++)
        {
            arr[i][j] = 0;
        }
    }
    return arr;
}

void Display1(int *ptr)
{
    for(int i = 0; i < 3; i++)
    {
        printf("%d\t",ptr[i]);
    }
    printf("\n");
}

int helper(int* rowSum, int *rowSumSize, int* colSum, int *colSumSize,int *p1,int *p2)
{
    int min1 = 0,min2 = 0,index1 = 0,index2 = 0;
    int i = 0,j = 0, c = -1;

    for(i = 0; i < *rowSumSize; i++)
    {
        if(c == -1 && rowSum[i] != -1){
            c++;
            min1 = rowSum[i];
        }
        if(rowSum[i] != -1)
        {
            if(min1 > rowSum[i]) 
            {
                min1 = rowSum[i];
                index1 = i;
            }
        }
    }
    c = -1;
    for(j = 0; j < *colSumSize; j++)
    {
        if(c == -1 && colSum[j] != -1){
            c++;
            min2 = colSum[j];
        }
        if(colSum[j] != -1)
        {
            if(min2 > colSum[j])
            {
                min2 = colSum[j];
                index2 = j;
            }
        }
    }
    if(min1 < min2){
        colSum[index2] -= min1;
        *p1 = index1;
        *p2 = index2;
        rowSum[index1] = -1;
        return min1;
    }else{
        rowSum[index1] -= min2;
        *p1 = index1;
        *p2 = index2;
        colSum[index2] = -1;
        return min2;
    }
}

void Display(int** customers)
{
    for(int i = 0; i < 3; i++)
    {
        for(int j = 0; j < 3; j++)
        {
            printf("%d\t",customers[i][j]);
        }
        printf("\n");
    }
}

int** restoreMatrix(int* rowSum, int *rowSumSize, int* colSum, int *colSumSize) 
{
    int **arr = init(*rowSumSize,*colSumSize);
    int i = 0,j = 0,num = 0;
    int n = 5;
   
    while(n--)
    {
        num = helper(rowSum,rowSumSize,colSum,colSumSize,&i,&j);
        printf("%d\n",num);
        arr[i][j] = num;
    }
    Display(arr);
}

int main()
{
    int arr[10] = {5,7,10};
    int brr[10] = {8,6,8};
    int **array;

    int rowSize = 3,colSize = 3;


    restoreMatrix(arr,&rowSize,brr,&colSize);

    return 0;
}