#include<stdio.h>
#include<stdlib.h>
#include<string.h>

 void reverse(char* str, int start, int end) 
 {
    while (start < end) 
    {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }
}

// Function to reverse substrings between each pair of parentheses
char* reverseParentheses(char* s) 
{
    int n = strlen(s);
    char* stack = (char*)malloc((n + 1) * sizeof(char));
    int stackIndex = 0;

    for (int i = 0; i < n; i++) 
    {
        if (s[i] == ')') 
        {
            int start = stackIndex - 1;
            // Pop characters until finding '('
            while (stack[start] != '(') 
            {
                start--;
            }
            // Reverse the substring between '(' and ')'
            reverse(stack, start + 1, stackIndex - 1);
            // Remove the '(' from the stack
            for (int j = start; j < stackIndex - 1; j++) 
            {
                stack[j] = stack[j + 1];
            }
            stackIndex--;
        } 
        else 
        {
            stack[stackIndex++] = s[i];
        }
    }

    // Null terminate the result
    stack[stackIndex] = '\0';
    return stack;
}

int main()
{
    char arr[50] = ("ta()usw((((a))))");
    char *ret = reverseParentheses(arr);

    printf("%s\n",ret);

}