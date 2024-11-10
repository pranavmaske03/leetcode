#include<stdio.h>
#include<stdbool.h>
#include<string.h>
#include<ctype.h>
#include<stdbool.h>

int CountPrime(int *arr,int size)
{
    bool flag = false;
    int count = 0;

    for(int i = 0; i < size; i++)
    {   
        flag = true;
        int no = arr[i];
        for(int j = 2; j <= no/2; j++)
        {
            if(no % j == 0)
            {
                flag = false;
                break;
            }
        }
        if(flag == true)
        {
            count++;
        }
    }
    return count;
}

int countPrimesInString(const char *str) 
{
    int arr[50] = {0};
    int i = 0,j = 0,no = 0,n = strlen(str),k = 0;
    int flag = 0;

    while(str[i] != '\0')
    {
        no = 0;
        flag = 0;
        if(str[i] >= '0' && str[i] <= '9')
        {
            flag = 1;
            for(j = i; j < n; j++)
            {
                if(str[j] >= '0' && str[j] <= '9')
                {
                    no = (no * 10) + (str[j] - '0');
                }
                else 
                {
                    break;
                }
            }
            arr[k++] = no;
        }
        if(flag == 1)
        {
            i = j;
        }
        else
        {
            i++;
        }
    }
    return CountPrime(arr,k);
}


int main()
{
   
    int arr1[] = {1, 4, 6, 8, 9};
    int arr2[] = {3,6,8};
    int arr[3][3] =  {{1, 2, 3}, {4, 5, 6}, {3, 6, 7} };
    char crr[50] = "abc3gto4k5";
    char ch = 'l';

    printf("\nResult = %d\n",countPrimesInString(crr));   
    //sortEvenOdd(arr1,10)    ;

    return 0;
}
