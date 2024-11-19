#include<stdio.h>
#include<stdbool.h>
#include<string.h>

bool rotateString(char* s, char* goal) 
{
    if(strlen(s) != strlen(goal)) return false;
    int i = 0,j = 0,k = 0;
    bool flag = false;

    while(goal[i] != '\0')
    {
        if(s[0] == goal[i])
        {
            flag = true;
            for(j = 0,k = i; goal[k] != '\0'; j++,k++)
            {
                if(s[j] != goal[k])
                {
                    flag = false;
                    break;
                }
            }
        }
        if(flag == true)
        {
            k = 0;
            while(s[j] != '\0')
            {
                if(s[j] != goal[k++])
                {
                    flag = false;
                    break;
                }
                j++;
            }
        }
        if(flag == true) break;
        i++;
    }
    return flag;
}
//  USING INBUILD METHODS

bool rotateString1(char s[], char goal[]) 
{
    if(strlen(s)!=strlen(goal))
    return false;
    char temp[2*strlen(s)+1];
    strcpy(temp,s);
    strcat(temp,s);
    if(strstr(temp,goal))
    return true;
    else
    return false;
}


int main()
{
    char arr[20] = "abcde";
    char brr[20] = "abced";

    bool bRet = rotateString(arr,brr);

    if(bRet == true) {
        printf("True\n");
    } else {
        printf("False \n");
    }

    return 0;
}