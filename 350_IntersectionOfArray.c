#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int* intersect(int* nums1, int nums1Size, int* nums2, int nums2Size, int* returnSize)
{
    int *intersect = (int*)calloc(1001,sizeof(int));
    int *new_array = (int*)calloc(nums1Size,sizeof(int));

    int k = 0;
    for(int i = 0; i < nums1Size; i++)
    {
        intersect[nums1[i]]++;
    }
    for(int i = 0; i < nums2Size; i++)
    {
        if(intersect[nums2[i]] > 0)
        {
            new_array[k++] = nums2[i];
            intersect[nums2[i]]--;
        }
    }
    free(intersect);
    *returnSize = k;
    return new_array;
}

int main()
{
    int arr[20] = {4,9,5},brr[20] = {9,4,9,8,4};

    int size = 0;
    int *ptr = intersect(arr,3,brr,5,&size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\t",ptr[i]);
    }

    return 0;
}