#include<stdio.h>
typedef struct {
    int value;
    int frequency;
} Element;

int compare(const void *a, const void *b) {
    Element *elemA = (Element *)a;
    Element *elemB = (Element *)b;
    if (elemA->frequency == elemB->frequency) {
        return elemB->value - elemA->value;
    } else {
        return elemA->frequency - elemB->frequency;
    }
}

void st(int *nums, int numsSize) {
    int freq[201] = {0};
    for (int i = 0; i < numsSize; i++) {
        freq[nums[i] + 100]++;
    }
    Element elements[numsSize];
    int idx = 0;
    for (int i = 0; i < 201; i++) {
        if (freq[i] > 0) {
            elements[idx].value = i - 100;
            elements[idx].frequency = freq[i];
            idx++;
        }
    }
    qsort(elements, idx, sizeof(Element), compare);
    int sortedIdx = 0;
    for (int i = 0; i < idx; i++) {
        for (int j = 0; j < elements[i].frequency; j++) {
            nums[sortedIdx++] = elements[i].value;
        }
    }
}

int *frequencySort(int *nums, int numsSize, int *returnSize) {
    *returnSize = numsSize;
    st(nums, numsSize);
    return nums;
}
int main()
{


    return 0;
}