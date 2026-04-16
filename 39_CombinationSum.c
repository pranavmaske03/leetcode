#include<stdio.h>
#include<stdlib.h>

/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** combinationSum(int* candidates, int candidatesSize, int target, int* returnSize, int** returnColumnSizes) {
    int** result = (int**)malloc(sizeof(int*) * 1000);
    *returnColumnSizes = (int*)malloc(sizeof(int) * 1000);
    *returnSize = 0;

    void backtrack(int start, int target, int* combination, int combinationSize) {
        if (target == 0) {
            result[*returnSize] = (int*)malloc(sizeof(int) * combinationSize);
            for (int i = 0; i < combinationSize; i++) {
                result[*returnSize][i] = combination[i];
            }
            (*returnColumnSizes)[*returnSize] = combinationSize;
            (*returnSize)++;
            return;
        }
        for (int i = start; i < candidatesSize; i++) {
            if (candidates[i] > target) continue;
            combination[combinationSize] = candidates[i];
            backtrack(i, target - candidates[i], combination, combinationSize + 1);
        }
    }

    int* combination = (int*)malloc(sizeof(int) * candidatesSize);
    backtrack(0, target, combination, 0);
    free(combination);
    return result;
}

int main() {
    int candidates[] = {2, 3, 6, 7};
    int target = 7;
    int returnSize;
    int* returnColumnSizes;
    int** result = combinationSum(candidates, sizeof(candidates) / sizeof(candidates[0]), target, &returnSize, &returnColumnSizes);
    for (int i = 0; i < returnSize; i++) {
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d ", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}