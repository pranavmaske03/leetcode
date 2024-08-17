#include<stdio.h>
#include<string.h>
#include<stdbool.h>

bool isIsomorphic(char* s, char* t) 
{
   if(strlen(s) != strlen(t)) return false;

    int map_s_to_t[256] = {0};
    int map_t_to_s[256] = {0};
    bool flag = true;

    for (int i = 0; s[i] != '\0'; i++) 
    {
        char c1 = s[i];
        char c2 = t[i];

        if(map_s_to_t[c1] != 0 && map_s_to_t[c1] != c2 || map_t_to_s[c2] != 0 && map_t_to_s[c2] != c1) 
        {
            flag = false;
            break;
        }
        if(flag == false) break;
        map_s_to_t[c1] = c2;
        map_t_to_s[c2] = c1;
    }
    return flag;
}

int main()
{
    char arr[10] = {"badc"};
    char brr[10] = {"baba"};

    bool bRet = isIsomorphic(arr,brr);
    if(bRet == true)
    {
        printf("string is isomorphic\n");
    }
    else
    {
        printf("string is NOT isomorphic\n");
    }

    return 0;
}