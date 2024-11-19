#include<stdio.h>
#include<stdbool.h>

char findTheDifference(char* s, char* t) 
{
    char result = '\0';

    for(int i = 0; s[i] != '\0'; i++)
    {
        result = result ^ s[i];
    }
    for(int i = 0; t[i] != '\0'; i++)
    {
        result = result ^ t[i];
    }
    return result;
}

int main()
{
    char arr[20] = "pranav";
    char brr[20] = "arnpalv";

    char ret = findTheDifference(arr,brr);

    printf("%c\n",ret);

    return 0;
}