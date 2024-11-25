#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

void Init(int *str)
{
    for(int i = 0; i < 26; i++)
    {
        str[i] = 0;
    }
}

char*** groupAnagrams(char (*strs)[50], int strsSize, int* returnSize) 
{
    int check1[26] = {0};
    int check2[26] = {0};
    bool flag = false;  
    int k = 0,m = 0,n = 0;

    char ***anagram = (char***) malloc(sizeof(char**));
    for(int i = 0; i < strsSize; i++)
    {
        char *s = strs[i];
       
        k = 0;
        anagram[n++] = (char**)malloc(sizeof(char*));
        anagram[m][k++] = s;

        for(int i = 0; s[i] != '\0'; i++)
        {
            check1[s[i] - 'a']++;
        }
        for(int j = i+1; j < strsSize; j++)
        {
            flag = true;
            char *s1 = strs[j];
            for(int i = 0; s1[i] != '\0'; i++)
            {
                check2[s1[i] - 'a']++;
            }
            for(int i = 0; i < 26; i++)
            {
                if(check1[i] != check2[i])
                {
                    flag = false;
                    break;
                }
            }
            if(flag == true) 
            {
                anagram[n++] = (char**)malloc(sizeof(char*));
                anagram[m][k++] = s1;
            }
            Init(check2);
        }
        m++;              
        Init(check1);
    }
    return anagram;
}

int main()
{
    char arr[50][50] = {{"eat"},{"tea"},{"tan"},{"ate"},{"nat"},{"bat"}};  // [["bat"],["nat","tan"],["ate","eat","tea"]]

    int size = 0;
    char ***ret = groupAnagrams(arr,6,&size);

    for(int i = 0; i < 3; i++)
    {   
        for(int j = 0; j < 3; j++)
        {
            printf("%s\t",ret[i][j]);   
        }
        printf("\n");
    }

    return 0;
}