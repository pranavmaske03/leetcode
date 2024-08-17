#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

bool isAnagram(char* s, char* t) 
{
    int *anagram = calloc(26, sizeof(int));
    bool flag = true;

    for(int i = 0; s[i] != '\0'; i++)
    {
        anagram[s[i] - 'a']++;
    }
    for(int i = 0; t[i] != '\0'; i++)
    {
        anagram[t[i] - 'a']--;
    }
    for(int i = 0; i < 26; i++)
    {
        if(anagram[i] != 0)
        {
            flag = false;
            break;
        }
    }
    return flag;
}

int main()
{
    char arr[] = "anagram";
    char brr[] = "nagaam";

    bool bRet = isAnagram(arr,brr);
    if(bRet == true)
    {
        printf("Anagram \n");
    }
    else
    {
        printf("Not Anagram\n");
    }

    return 0;
}