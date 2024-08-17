#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int* plusOne(int* digits, int digitsSize) 
{   
    int iCnt = 0;
    bool flag = false;
    int *ptr = NULL;

    for(iCnt = digitsSize-1; iCnt >= 0; iCnt--)
    {
        if(digits[iCnt] == 9)
        {
            digits[iCnt] = 0;
            if(iCnt == 0)
            {
                flag = true;
            }
            continue;
        }
        if(digits[iCnt] < 9)
        {
            digits[iCnt]++;
            break;
        }
    }
    if(flag == true)
    {
        ptr = (int*)malloc(sizeof(int) * digitsSize+1);
        ptr[0] = 1;
        for(iCnt = 1; iCnt < digitsSize+1; iCnt++)
        {
            ptr[iCnt] = 0;
        }
        //*returnSize = digitsSize+1;
        return ptr;
    }
   // *returnSize = digitsSize+1;
    return digits;
}

int main()
{
    int Arr[] = {8,9,9};
    int *ret = NULL;

    int size = 3;

    ret = plusOne(Arr,size);
    for(int iCnt = 0; iCnt < size; iCnt++)
    {
        printf("%d\t",ret[iCnt]);
    }
    printf("\n");

    return 0;
}

/*
 Note: The returned array must be malloced, assume      
 caller calls free().                                  
int *plusOne(int *digits, int digitsSize, int *returnSize) {
    *returnSize = digitsSize;
    int *plusOne = malloc(digitsSize * sizeof(int));
    if (plusOne == NULL)
        return (NULL);
    for (int i = 0; i < digitsSize; i++)
        plusOne[i] = digits[i];
    
    plusOne[digitsSize - 1]++;
    for (int i = digitsSize - 1; i - 1 >= 0; i--)
        if (plusOne[i] == 10) {
            plusOne[i] = 0;
            plusOne[i - 1]++;
        }

    if (plusOne[0] == 10) {
        (*returnSize)++;
        plusOne = realloc(plusOne, *returnSize * sizeof(int));
        if (plusOne == NULL)
            return (NULL);
        memmove(plusOne + 1, plusOne, digitsSize * sizeof(int));
        plusOne[0] = 1;
        plusOne[1] = 0;
    }
    return (plusOne);
}


int* plusOne(int* digits, int digitsSize, int* returnSize) 
{
    int i = 0;
    bool flag = false;

    for(i = digitsSize-1;i >= 0;i--)
    {
        if(digits[i] == 9)
        {
    
            digits[i] = 0;
            if(i == 0)
            {
                flag = true;
            }
            continue;
        }
        else
        {
            digits[i] = digits[i] + 1;
            break;
        }
    }

    if(flag == true)
    {
        int * newArr = NULL;
        newArr = (int *)malloc(sizeof(int)*(digitsSize+1));
        newArr[0] = 1;
        for(i = 1;i <= digitsSize;i++)
        {
            newArr[i] = 0;
        }
        *returnSize = digitsSize+1;
        return newArr;
    }
    else
    {
        *returnSize = digitsSize;
        return digits;
    }
}

*/