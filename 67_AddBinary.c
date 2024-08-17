#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void AddBinary(char *a,char *b)
{
    int sizeA = strlen(a);
    int sizeB = strlen(b);
    int sizeOutput = (sizeA > sizeB ? sizeA : sizeB) + 1;
    char * output = (char *)malloc(sizeOutput + 1);
    int sum = 0;    

    printf("%d\t%d\t%d\n",sizeA,sizeB,sizeOutput);
    
    output[sizeOutput] = '\0';
    
    while(sizeA > 0 || sizeB > 0 || sum > 0) 
    {
        if(sizeA > 0) 
        {
            sum += a[--sizeA] - '0';
        }
        if(sizeB > 0) 
        {
            sum += b[--sizeB] - '0';
        }
        output[--sizeOutput] = sum % 2 + '0';
        sum /= 2;
    }
    while(*output != '\0')
    {
        printf("%c\t",*output);
        output++;
    }
}

int main()
{
    char str1[10];
    char str2[10];

    printf("Enter first binary number :\n");
    scanf("%[^'\n']s",str1);

    printf("Enter second binary number:\n");
    scanf(" %[^'\n']s",str2);

    AddBinary(str1,str2);

    return 0;
}