#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

//sorting
int compare(const void* a, const void* b) {
    return (*(int*)a - *(int*)b);
}

bool containsDuplicate(int* nums, int numsSize) 
{
    bool flag = false;
    // Sort ascending order
    qsort(nums, numsSize, sizeof(int), compare);

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] == nums[i - 1]) {
            flag = true;
            break;
        }
    }
    return flag;
}

int main()
{
    int arr[20] = {1,2,3,5};
    bool ret = containsDuplicate(arr,4);
    if(ret == true)
    {
        printf("Yes\n");
    }
    else
    {
        printf("NO\n");
    }

    return 0;
}


/*
    #define MAGIC 5000
bool containsDuplicate(int* nums, int numsSize) 
{
    uint64_t poormanhash[MAGIC] = {0};
    for (int i = 0; i < numsSize; i++) 
    {
        int v = nums[i] +  1000000001;
        int mod = v % MAGIC;
        uint64_t loc = poormanhash[mod];
        if (loc != 0 && loc % v == 0) {
            return true;
        } if (loc == 0) {
            poormanhash[mod] = v;
        } else {
            poormanhash[mod] *= v;
        }
    }
    return false;
}
*/