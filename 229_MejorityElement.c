#include<stdio.h>
#include<stdlib.h>
#include<limits.h>

int* majorityElement(int* nums, int numsSize, int* returnSize) 
{
    int n = numsSize;
    int el1 = INT_MIN;
    int el2 = INT_MIN;
    int cnt1 = 0;
    int cnt2 = 0;

    for(int i=0;i<n;i++) 
    {
        if(cnt1 == 0 && el2 != nums[i])
        {
            el1 = nums[i];
            cnt1=1;
        }
        else if(cnt2==0 && el1!=nums[i])
        {
            el2=nums[i];
            cnt2=1;
        }
        else if(nums[i]==el1)
        {
            cnt1++;
        }
        else if(nums[i]==el2)
        {
            cnt2++;
        }
        else
        {
            cnt1--;
            cnt2--;
        }  
    }
    cnt1=0;
    cnt2=0;
    for(int i=0;i<n;i++)
    {
        if(nums[i]==el1)
        {
            cnt1++;
        }
        if(nums[i]==el2)
        {
            cnt2++;
        }
    }
    int a = numsSize / 3;
    int *list = (int*)malloc(2 * sizeof(int));
    int index = 0;
    if(cnt1 > a)
    {
        list[index++]=el1;
    }
    if(cnt2 > a && el2 != el1)
    {
        list[index++]=el2;

    }
     *returnSize = index;
    return list;

}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* majorityElement1(int* arr, int numsSize, int* returnSize) {
    int k =0,m = 0;
    int*  nums = (int*)malloc(numsSize * sizeof(int));
    for(int i = 0;i<numsSize;i++){
        if(arr[i] == -2000000000){
            continue;
        }
        int count = 1;
        for(int j = i+1;j<numsSize;j++)
        {

            printf("iteration = %d\n",++m);
            if(arr[i] == arr[j]){
                count++;
                arr[j] = -2000000000;
            }

        }
        if(count> (numsSize/3)){
            nums[k++] = arr[i];
        }
    }  
    *returnSize = k;
    return nums;

}

int main()
{
    int arr[] = {-2,5,3,2,3,5,5,3,3,5};

    int size = 0;
    majorityElement1(arr,10,&size);
    //printf("%d\t%d\n",INT_MAX,INT_MIN);

    return 0;
}