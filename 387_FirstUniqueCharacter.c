#include<stdio.h>

int firstUniqChar(char* s) 
{
    char *tmp = s;
    int arr[26] = {0};
    int iPos = -1;

    while(*tmp != '\0')
    {
        arr[*tmp - 'a']++;
        tmp++;
    }
    int i = 0;
    while(*s != '\0')
    {
        if(arr[*s - 'a'] == 1)
        {
            iPos = i;
            break;
        }
        i++;
        s++;
    }
    return iPos;
}

int main()
{
    char arr[] = "loveleetcode";
    int ret = firstUniqChar(arr);
    printf("index = %d\n",ret);

    return 0;
}