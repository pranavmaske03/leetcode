#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int maximumGain(char* s, int x, int y) 
{
    int total_count = 0;
    int n = strlen(s);
    char stack[n];
    int top = -1;

    if (x > y) 
    {
        // Prioritize "ab" pairs if x > y
        for (int i = 0; i < n; i++) {
            if (top >= 0 && stack[top] == 'a' && s[i] == 'b') {
                top--; // Remove 'a' from stack
                total_count += x;
            } else {
                stack[++top] = s[i]; // Add current character to stack
            }
        }

        // Process remaining characters in the stack for "ba" pairs
        int new_top = -1;
        for (int i = 0; i <= top; i++) {
            if (new_top >= 0 && stack[new_top] == 'b' && stack[i] == 'a') {
                new_top--; // Remove 'b' from stack
                total_count += y;
            } else {
                stack[++new_top] = stack[i]; // Add current character to new stack
            }
        }
    } 
    else 
    {
        // Prioritize "ba" pairs if y >= x
        for (int i = 0; i < n; i++) {
            if (top >= 0 && stack[top] == 'b' && s[i] == 'a') {
                top--; // Remove 'b' from stack
                total_count += y;
            } else {
                stack[++top] = s[i]; // Add current character to stack
            }
        }

        // Process remaining characters in the stack for "ab" pairs
        int new_top = -1;
        for (int i = 0; i <= top; i++) {
            if (new_top >= 0 && stack[new_top] == 'a' && stack[i] == 'b') {
                new_top--; // Remove 'a' from stack
                total_count += x;
            } else {
                stack[++new_top] = stack[i]; // Add current character to new stack
            }
        }
    }

    return total_count;
}

int maximumGain1(char* s, int x, int y) 
{
    //a, b, x, y = ("a", "b", x, y) if x > y else ("b", "a", y, x)

    char a, b;
    int _x = x, _y = y;
    if (x > y) {
        a = 'a';
        b = 'b';
        x = _x;
        y = _y;
    } else {
        a = 'b';
        b = 'a';
        x = _y;
        y = _x;
    }
    int count_a = 0, count_b = 0;
    int score = 0;

    for (char* c = s; *c != 0; ++c) 
    {
        if (*c == b) 
        {
            if(count_a > 0) 
            {
                score += x;
                --count_a;
            }
            else{
                ++count_b;
            }
        } 
        else if(*c == a) 
        {
            ++count_a;
        }
        else
        {
            score += y * (count_a < count_b ? count_a : count_b);
            count_a = 0, count_b = 0;
        }
    }
    score += y * (count_a < count_b ? count_a : count_b);

    return score;
}

int main()
{   
    char arr[100] = {"cdbcbbaaabab"};

    int ret = maximumGain(arr,4,5);
    printf("%d\n",ret);
    return 0;
}