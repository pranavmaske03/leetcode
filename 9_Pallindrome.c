#include<stdio.h>
#include<stdbool.h>

bool isPallindrome(char *s)
{
    int i = 0,non_space = 0;
    bool flag = true;

    for(int i = 0; s[i] != '\0'; i++)
    {
        if((s[i] >= 'A') && (s[i] <= 'Z'))
        {
            s[i] = s[i] + 32;
        }
        if((s[i] >= 97) && (s[i] <= 122) || (s[i] >= 48) && (s[i] <= 57))
        {
            s[non_space] = s[i];
            non_space++;
        }        
    }
    s[non_space] = '\0';
    i = 0;
    non_space--;

    while(i < non_space)
    {   
        printf("%c = %c\n",s[i],s[non_space]);
        if(s[i] != s[non_space])
        {
            flag = false;
            break;
        }
        i++;
        non_space--;
    }
    return flag;
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