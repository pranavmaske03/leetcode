#include<stdio.h>

int RomanToInteger(char *str)
{
    int iValue = 0;

    while(*str != '\0')
    {

        if((*str == 'I'))
        {
            str++;
            if(*str == 'V')
            {
                iValue = iValue + 4;
            }
            else if(*str == 'X')
            {
                iValue = iValue + 9;
            }
            else
            {
                iValue = iValue + 1;
                str--;
            }
        }
        else if(*str == 'V')
        {
            iValue = iValue + 5;
        }
        else if(*str == 'X')
        {
            str++;
            if(*str == 'L')
            {
                iValue = iValue + 40;
            }
            else if(*str == 'C')
            {
                iValue = iValue + 90;
            }
            else
            {
                iValue = iValue + 10;
                str--;
            }
        }
        else if(*str == 'L')
        {
            iValue = iValue + 50;
        }
        else if(*str == 'C')
        {
            str++;
            if(*str == 'D')
            {
                iValue = iValue + 400;
            }
            else if(*str == 'M')
            {
                iValue = iValue + 900;
            }
            else
            {
                iValue = iValue + 100;
                str--;
            }
        }
        else if(*str == 'D')
        {
            iValue = iValue + 500;
        }
        else if(*str == 'M')
        {
            iValue = iValue + 1000;
        }
        str++;
    }

    return iValue;
}

int main()
{
    char Arr[50];

    printf("String must contain lettes : ('I', 'V', 'X', 'L', 'C', 'D', 'M')\n");
    printf("String length must be lower than 15.\n");

    printf("Enter RomanNumber :\n");
    scanf("%[^'\n']s",Arr);  

    int ret = RomanToInteger(Arr);
    printf("Number is : %d\n",ret);

    return 0;
}