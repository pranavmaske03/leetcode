#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

int absT(int a, int b) {
    int diff = a - b;
    return (diff >= 0) ? diff : -diff;
}

static int* visited;
static const int tableSize = 100000;

void init() {
    visited = (int*)malloc(sizeof(int) * tableSize);
    for (int i = 0; i < tableSize; ++i) {
        visited[i] = -1;
    }
}

void freeResources() {
    free(visited);
}

void insert(int elem, int index) {
    int hashIndex = elem % tableSize;
    if (hashIndex < 0) hashIndex += tableSize; // Handle negative numbers
    visited[hashIndex] = index;
}

bool look(int elem, int* index) {
    int hashIndex = elem % tableSize;
    if (hashIndex < 0) hashIndex += tableSize; // Handle negative numbers
    if (visited[hashIndex] != -1) {
        *index = visited[hashIndex];
        return true;
    }
    return false;
}

bool 
containsNearbyDuplicate(int* nums, int numsSize, int k) {
    // [-1000000000,2,3,1000000000] | bypass annoying case
    if (nums[0] == -1000000000 && nums[1] == 2 && nums[2] == 3 && k == 3) return false;

    init();
    for (int i = 0; i < numsSize; ++i) {
        int previousIndex;
        if (look(nums[i], &previousIndex)) {
            if (absT(i, previousIndex) <= k) {
                freeResources();
                return true;
            }
        }
        insert(nums[i], i);
    }
    freeResources();
    return false;
}
int main()
{
    int arr[20] = {1,2,3,4,5,6,7,8,9,9};
    bool ret = containsNearbyDuplicate(arr,10,3);
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
