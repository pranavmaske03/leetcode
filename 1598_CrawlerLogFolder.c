#include<stdio.h>
#include<string.h>

int minOperations(char (*arr)[20], int logsSize) 
{
    int count = 0;

    for(int i = 0; i < logsSize; i++)
    {
        if(strcmp(arr[i],"../") == 0)
        {
            if(count < 0) count--;
        }
        else if(strcmp(arr[i],"./") == 0)
        {
            continue;
        }
        else
        {
            count++;
        }
    }
    return count;
}

int main()
{
    char arr[][20] = {"./","wz4/","../","mj2/","../","../","ik0/","il7/"};
    int ret = minOperations(arr,8);

    printf("%d\n",ret);

    return 0;
}