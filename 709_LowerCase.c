#include<stdio.h>

char* toLowerCase(char* s) 
{
    int gap = 32;
    int i = 0;

    while(s[i] != '\0')
    {
        if((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] += 32;
        }
        i++;
    }
    return s;
}

int main()
{
    char arr[30] = "PRANAV";

    printf("%s\n",toLowerCase(arr));
    
    return 0;
}