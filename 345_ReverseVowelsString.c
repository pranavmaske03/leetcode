#include<stdio.h>
#include<stdbool.h>
#include<string.h>

char* reverseVowels(char* s) 
{
    int start = 0,end = strlen(s)-1;
    char ch1 = '\0',ch2 = '\0',temp = '\0';
    bool flag1 = true,flag2 = true;

    while(start < end)    
    {   
        if((s[start] == 'a') ||(s[start] == 'e') ||(s[start] == 'i') ||(s[start] == 'o') ||(s[start] == 'u') ||(s[start] == 'A') ||(s[start] == 'E') ||(s[start] == 'I') ||(s[start] == 'O') ||(s[start] == 'U'))
        {
            ch1 = s[start];
            flag1 = false;
        }
        if((s[end] == 'a') ||(s[end] == 'e') ||(s[end] == 'i') ||(s[end] == 'o') ||(s[end] == 'u') ||(s[end] == 'A') ||(s[end] == 'E') ||(s[end] == 'I') ||(s[end] == 'O') ||(s[end] == 'U'))
        {
            ch2 = s[end];
            flag2 = false;
        }
        if(ch1 != '\0' && ch2 != '\0')
        {
            s[start] = ch2;
            s[end] = ch1;

            ch1 = '\0';
            ch2 = '\0';

            flag1 = true;
            flag2 = true;
        }
        if(flag1 == true) start++;
        if(flag2 == true) end--;
    }
}

int main()
{
    char Arr[20] = {"Leetcode"};

    reverseVowels(Arr);
    printf("%s\n",Arr);

    return 0;
}