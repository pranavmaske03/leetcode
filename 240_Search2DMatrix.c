#include<stdio.h>
#include<stdbool.h>

bool searchMatrix(int (*matrix)[50], int matrixSize, int* matrixColSize, int target)
{
    bool flag = false;

    for(int i = 0; i < matrixSize; i++)
    {
        int low = 0,high = *matrixColSize,mid = 0;
        while(low <= high)
        {
            mid = low + (high - low) / 2;

            if(matrix[i][mid] == target)
            {
                flag = true;
                break;
            }
            else if(matrix[i][mid] < target)
            {
                low = mid + 1;
            }
            else
            {
                high = mid - 1;
            }
        }
        if(flag == true) break;
    }
    return flag;
}



bool searchMatrix1(int** matrix, int matrixSize, int* matrixColSize, int target)
{
    uint i = *matrixColSize - 1;
    uint j = 0;

    while (i < *matrixColSize && j < matrixSize) {
        if (matrix[j][i] < target) {
            j++;
        } else if (matrix[j][i] > target) {
            i--;
        } else {
            return true;
        }
    }

    return false;

}

int main()
{
    int matrix[50][50] = {{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};

    int row = 5,col = 5;
    bool bRet = searchMatrix(matrix,row,&col,100);
    if(bRet == true)
    {
        printf("Element found \n");
    }
    else
    {
        printf("Element NOT found \n");
    }
    return 0;
}