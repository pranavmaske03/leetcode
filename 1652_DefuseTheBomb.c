#include<stdio.h>
#include<stdlib.h>

int* decrypt(int* code, int codeSize, int k,int *returnSize) 
{
    int n = 0,i = 0,sum = 0,m = 0,j = 0;
    int *arr = calloc(codeSize,sizeof(int));

    if(k == 0) return arr;
    if(k > 0)
    {
        n = 0;
        while(n < codeSize)   
        {
            m = k;
            sum = 0;
            i = n+1;
            while(m--)
            {
                if(i >= codeSize) i = 0;
                if(n == i) i++;
                sum += code[i];
                printf("%d\t",code[i]);
                i++;
            }
            printf("\n");
            n++;
            arr[j++] = sum;
        }
    }
    else
    {
        n = 0;
        while(n < codeSize)   
        {
            m = k * (-1);
            sum = 0;
            i = n-1;
            while(m--)
            {
                if(n == i) i--;
                if(i < 0) i = codeSize-1;
                if(i >= codeSize) i = 0;
                sum += code[i];
                printf("%d\t",code[i]);
                i--;
            }
            n++;
            printf("\n");
            arr[j++] = sum;
        }
    }
    *returnSize = j;
    return arr;
}

int main()
{
    int arr[] = {5,2,2,3,1}; //[7,8,9,5,9]
    int size = 0;
    int *ret =  decrypt(arr,5,3,&size);

    for(int i = 0; i < size; i++)
    {
        printf("%d\t",ret[i]);
    }

    return 0;
}