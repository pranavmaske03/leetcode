#include<stdio.h>
#include<stdlib.h>


void Display(int *arr,int size)
{
    for(int i = 0; i < size; i++)
    {
        printf("%d\t",arr[i]);
    }
    printf("\n");
}

void Init(int *arr,int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[i] = 0;
    }
}

int* topKFrequent(int* nums, int numsSize, int k) 
{
    int min = 0,max = 0,i = 0,j = 0;
    for(i = 0; i < numsSize; i++)        
    {
        min = min > nums[i] ? nums[i] : min;
        max = max < nums[i] ? nums[i] : max;
    }

    printf("%d\t%d\n",max,min);
    if(min < 0) min = min * (-1);
    int mapping_plus[max+1];
    int mapping_minus[min+1];
       
    Init(mapping_plus,max+1);
    Init(mapping_minus,min+1);

    for(i = 0; i < numsSize; i++)
    {
        if(nums[i] >= 0)
        {
            mapping_plus[nums[i]]++;
        }
        else if(nums[i] < 0)
        {
            mapping_minus[nums[i]* -1]++;
        }
    }
    Display(mapping_plus,max+1);
    Display(mapping_minus,min+1);
    int *ret = calloc(k,sizeof(int));
    int max1 = 0,max2 = 0,idx1 = 0,idx2 = 0;
    while(k--)
    {
        max1 = 0;
        max2 = 0;
        for(i = 0; i <= max; i++)
        {
            if(max1 < mapping_plus[i])
            {
                max1 = mapping_plus[i];
                idx1 = i;
            }
        }
        for(i = 0; i <= min; i++)
        {
            if(max2 < mapping_minus[i])
            {
                max2 = mapping_minus[i];
                idx2 = i;
            }
        }
        if(max1 >= max2)
        {
            ret[j++] = idx1;
            mapping_plus[idx1] = 0;
        }
        else
        {
            ret[j++] = idx2*-1;
            mapping_minus[idx2] = 0;
        }
    }
    Display(ret,j);
}

int main()
{
    int arr[] = {-1,-1};
    int size = 1;

    topKFrequent(arr,2,size);

    return 0;
}