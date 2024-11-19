#include<stdio.h>
#include<string.h>

int countGoodSubstrings(char* s) 
{
    int len = strlen(s);
    int i = 0,k = 0,count = 0;

    if(len < 3) return 0;

    for(int i = 0,k = 2; k < len; i++,k++)
    {
        printf("%d\t%d\n",k,len);
        if((s[i] != s[i+1]) && (s[i] != s[k]) && (s[i+i] != s[k]))
        {   
            count++;
        }
    }
    return count;
}

int main()
{
    char arr[] = "aababcabc";
    printf("%d\n",countGoodSubstrings(arr));
    return 0;
}