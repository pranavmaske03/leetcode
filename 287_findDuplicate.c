#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int findDuplicate(int* nums, int numsSize) 
{
    int *check = calloc(numsSize+1,sizeof(int));
    int i = 0;
    for(int i = 0; i < numsSize; i++)
    {
        check[nums[i]]++;
    }
    for(i = 0; i < numsSize+1; i++)
    {
        printf("%d\t",check[i]);
        if(check[i] >= 2)
        {
            break;
        }
    }
    free(check);
    return i;
}

int findDuplicate1(int* nums, int numsSize) 
{
    int t=nums[0];
    int h=nums[0];
    do
    {
        t=nums[t];
        h=nums[nums[h]];
    }while(t!=h);
    printf("%d\t%d\n",t,h);
    t=nums[0];
    while(t!=h)
    {
        t=nums[t];
        h=nums[h];
    }
    return t;
}

int main()
{
    int arr[] = {3,1,3,4,2};

    printf("check = %d\n",findDuplicate1(arr,5));
    return 0;
}