#include<stdio.h>
#include<stdlib.h>

int cmpfunc (const void * a, const void * b) {
   return ( *(int*)a - *(int*)b );
}
int min(int a,int b){
    return (a < b ? a : b);
}

int minDifference(int* nums, int numsSize) 
{
    if(numsSize <= 4) return 0;
    qsort(nums, numsSize, sizeof(int), cmpfunc);

    int a = min(nums[numsSize-4] - nums[0],nums[numsSize-3] - nums[1]);
    int b = min(nums[numsSize-2] - nums[2],nums[numsSize-1] - nums[3]);

    return min(a,b);
}

int main()
{
    int Arr[10] = {6,6,0,1,1,4,6};

    int ret = minDifference(Arr,7);

    printf("%d\n",ret);

    return 0;
}