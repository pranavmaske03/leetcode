#include<stdio.h>
#include<string.h>

void Init(int *arr,char *s,int size)
{
    for(int i = 0; i < size; i++)
    {
        arr[s[i]] = 0;
    }
}
int lengthOfLongestSubstring(char* s) 
{
    int max = 0,max1 = 0;
    int arr[256] = {0};
    int len = strlen(s);

    for(int i = 0; i < len; i++)
    {
        if(arr[s[i]] == 0)
        {
            arr[s[i]]++;
            max++;
        }
        else if(arr[s[i]] != 0)
        {
            if(max1 < max) max1 = max;
            Init(arr,s,i+1);
            i = i - 1;
            max = 0;
        }
    }
    return max1 > max ? max1 : max;
}

int lengthOfLongestSubstring1(char* s) 
{
    int len = strlen(s);
    int maxLength = 0;
    int start = 0; 
    int charIndex[128] = {0}; 

    for (int end = 0; end < len; end++) 
    {
        if (charIndex[s[end]] > start) 
        {
            start = charIndex[s[end]];
        }

        charIndex[s[end]] = end + 1; 
    
        int currentLength = end - start + 1;
        printf("%d %d %d %d\n",end,start,currentLength,maxLength);
        if (currentLength > maxLength) 
        {
            maxLength = currentLength;
        }
    }

    return maxLength;
}

int main()
{   
    char arr[] = "abcdefghie";

    printf("%d\n",lengthOfLongestSubstring1(arr));

    return 0;
}