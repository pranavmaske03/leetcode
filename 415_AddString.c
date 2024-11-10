#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char *reverse(char *str,int right)
{
    int left = 0;
    while(left < right)
    {
        char temp = str[left];
        str[left] = str[right];
        str[right] = temp;

        right--;
        left++;
    }
    return str;
}

char* addStrings(char* num1, char* num2) 
{
    int i = strlen(num1) - 1,j = strlen(num2) - 1,carry = 0;
    int max = (i > j ? i : j) + 1;
    char *result = calloc(++max,sizeof(char));
    int k = 0;

    while(i >= 0 || j >= 0 || carry > 0)
    {
        int sum = carry;
        if(i >= 0)
        {
            sum += num1[i--] - '0';
        }
        if(j >= 0)
        {
            sum += num2[j--] - '0';
        }
        result[k++] = (sum % 10) + '0';
        carry = sum / 10;
    }
    return reverse(result,k-1);
}
int main()
{
    char arr[] = "1";
    char brr[] = "9";

    printf("%s\n",addStrings(arr,brr));

    return 0;
}