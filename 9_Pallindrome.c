#include<stdio.h>
#include<stdbool.h>

bool isPallindrome(char *s)
{
    if (!s) return false;

    int left = 0;
    int right = 0;

    /* find last index */
    while (s[right] != '\0') right++;
    if (right == 0) return true;
    right--; /* index of last character */

    while (left < right)
    {
        /* move left to next alphanumeric */
        while (left < right)
        {
            char c = s[left];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                break;
            left++;
        }

        /* move right to previous alphanumeric */
        while (left < right)
        {
            char c = s[right];
            if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c >= '0' && c <= '9'))
                break;
            right--;
        }

        if (left >= right) break;

        char cl = s[left];
        char cr = s[right];

        /* normalize uppercase to lowercase for comparison */
        if (cl >= 'A' && cl <= 'Z') cl = cl + ('a' - 'A');
        if (cr >= 'A' && cr <= 'Z') cr = cr + ('a' - 'A');

        if (cl != cr) return false;

        left++;
        right--;
    }

    return true;
}

int main()
{
    char str[50] = {"ab_a"};

    bool bret =  isPallindrome(str);    
    if(bret == true)
    {
        printf("string is pallindrome \n");
    }
    else
    {
        printf("string is not pallindrome \n");
    }

    return 0;
}