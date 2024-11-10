#include<stdio.h>
#include<stdlib.h>


int** construct2DArray(int* original, int originalSize, int m, int n,int* returnSize, int** returnColumnSizes) 
{

    int **mat = (int**)malloc(sizeof(int*) * m);
    if(m*n != originalSize) 
    {
        *returnSize = 0;
        free(mat);
        return NULL;
    }

    *returnColumnSizes =  (int*)malloc(sizeof(int) * m);
    *returnSize = m;

    for(int i = 0,idx = 0; i < m; i++)
    {
        mat[i] = (int*)malloc(sizeof(int) * n);
        for (int j = 0; j < n; j++) {
            mat[i][j] = original[idx];
            idx++;
        }
        (*returnColumnSizes)[i] = n;
    }
    
    for (int i = 0, idx = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d\t",mat[i][j]);
        }
        printf("\n");
    }
    return mat;
}

int main()
{
    int arr[] = {1,2,3,4};
    int *brr = (int*)malloc(sizeof(int));
    int val = 0;

    int **ret = construct2DArray(arr,4,2,2,&val,&brr);

    return 0;
}