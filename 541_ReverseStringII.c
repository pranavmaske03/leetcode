#include<stdio.h>
#include<string.h>

void reverse(char* s,int k)
{
    int start = 0;
    int end = k-1;
    if(strlen(s) < k) end = strlen(s)-1;

    while(start < end)
    {
        char temp = s[start];
        s[start] = s[end];
        s[end] = temp;

        start++;
        end--;
    }
}

char* reverseStr(char* s, int k) 
{
    int len = strlen(s);
    int i = 0;

    while(i < len)
    {
        reverse(&s[i],k);
        printf("i = %d\n",i);
        i += (2 * k);
    }
    printf("Updated string : %s\n",s);
    return s;
}

int main()
{
    char arr[] = "abcd";
    printf("Original string : %s\n",arr);
    reverseStr(arr,2);

    return 0;
}