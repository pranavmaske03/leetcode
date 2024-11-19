#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

char *LongComPrefix(char **str, int size)
{
    char *Brr = (char*)malloc(sizeof(char)*1);
    int i = 0,j = 0,k = 0;
    bool flag = true;

    while(str[0][j] != '\0')
    {
        flag = true;
        for(int i = 0; i < size-1; i++)
        {
            if(str[i][j] == '\0')
            {
                flag = false;
                break;
            }

            if(str[i][j] != str[i+1][j])
            {
                flag = false;
                break;
            }
        }
        if(flag == false)
        {
            break;
        }
        else
        {   
            Brr = realloc(Brr,sizeof(char));
            Brr[k] = str[i][j];
            k++;
            j++;
        }
    }
    return Brr;
}

/*
    char *LongComPrefix(char **strs, int size)
{
    for(int i = 1; i < size; i++)
    {   
        for(int j = 0; strs[0][j]; j++)
        {   
            if(!(strs[i][j]) ||(strs[0][j] != strs[i][j]))        // terminate loop if chars differ
            {   
                strs[0][j] = '\0';
                break;
            }

        }
    }
    return strs[0];
}

*/
int main()
{
    char *rptr = NULL;
    char *arr[] = {"flower", "flow", "float"};

    rptr = LongComPrefix(arr,3);

    printf("%s\n",rptr);

    return 0;
}