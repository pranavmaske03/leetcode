#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define ERR_NOTFOUND -1

int strStr(char* haystack, char* needle) 
{   
    int iPos = ERR_NOTFOUND;
    int iCnt = 0;
    char *q = NULL;
    char *p = NULL;
    bool flag = false;

    while(*haystack != '\0')
    {   
        flag = true;
        if(*haystack == *needle)
        {   
            q = haystack;
            p = needle;
            while(*p != '\0')
            {
                printf("%c\t",*p);
                printf("%c\n",*q);
                if(*p != *q)
                {   
                    flag = false;
                    break;
                }
                q++;
                p++;
            }
            if(flag == true)
            {
                iPos = iCnt;
                break;
            }
        }
        haystack++;
        iCnt++;
    }
    return iPos;
}

void Display(char *str)
{
    while(*str != '\0')
    {
        printf("%c\t",*str);
        str++;
    }
}

int main()
{
    char Arr[] = {"leetcode"};
    char Brr[] = {"leeto"};
    int ret = 0;

    ret = strStr(Arr,Brr);
    printf("%d\n",ret);

    //Display(Brr);

    return 0;
}