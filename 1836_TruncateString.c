#include<stdio.h>

char* truncateSentence(char* s, int k) 
{
    int j = 0,i = 0;
    for(i = 0; s[i] != '\0'; i++)    
    {
        if(s[i] == ' ')
        {
            j++;
        }
        if(j == k) 
        {
            s[i] = '\0';
            break;
        }
    }
    return s;
}

int main()
{
    char arr[] = "Hello how are you Contestant";

    printf("%s\n",truncateSentence(arr,4));

    return 0;
}