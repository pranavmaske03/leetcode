/*
    Problem : twoSum using brut force algoritham.
*/

#include<stdio.h>
#include<stdlib.h>

int* twoSum(int *Arr,int length,int target)
{
    int i = 0,j = 0;
    int *arr = malloc(sizeof(int) * 2);

    for(i = 0; i < length; i++)
    {
        for(j = i+1; j < length; j++)
        {
            if(Arr[i] + Arr[j] == target)
            {
                arr[0] = i;
                arr[1] = j;
                return arr;
            }
        }
    }
    return NULL;
}

int main()
{
    int size = 0,i = 0,j = 0,value = 0;
    int *ptr = NULL;

    printf("Enter length of the array : \n");
    scanf("%d",&size);

    ptr = malloc(sizeof(int) * size);

    printf("Enter elements of the array : \n");
    for(i = 0; i < size; i++)
    {
        scanf("%d",&ptr[i]);
    }

    printf("Enter the target value :\n");
    scanf("%d",&value);

    ptr = twoSum(ptr,size,value);
    for(i = 0; i < 2; i++)
    {
        printf("%d\t",ptr[i]);
    }
}