#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int lengthOfLastWord(char* s) 
{
    int count = 0;
    char *q = NULL;

    while(*s != '\0')    
    {
        if(*s == ' ')
        {   
            q = s;
            while(*q != '\0')
            {
                if(*q != ' ')
                {
                    count = 0;
                    break;
                }
                q++;
            }
        }
        else
        {
            count++;
        }
        s++;
    }
    return count;
}

int lengthOfLastWord1(char * s)
{
    int length = 0,i=1;

    if(s[0]!=' ')
    {
        length++;
    }
    while(s[i]!='\0')
    {
        if(s[i]!=' ')
        {
            if(s[i-1]==' ')
            {
                length = 1;
            }
            else
            {
                length++;
            }
        }
        i++;
    }
    return length;
}

int main()
{
    char Arr[] = {"   fly me   to   the moon  "};

    int ret = lengthOfLastWord(Arr);
    printf("lentgh is : %d\n",ret);

    ret = lengthOfLastWord1(Arr);
    printf("lentgh is : %d\n",ret);

    return 0;
}