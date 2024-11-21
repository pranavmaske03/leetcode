#include<stdio.h>
#include<limits.h>

int myAtoi(char* s) 
{
    int sign = 0,i = 0;
    long long int ans = 0;

    while(s[i] == ' ')i++;

    if(s[i] == '+') {
        sign = 0;
        i++;
    } else if(s[i] == '-') {
        sign = 1;
        i++;
    }

    while(s[i] == '0') i++;

    while(s[i] >= '0' && s[i] <= '9') {
        if(ans > INT_MAX) {
            if(sign) return INT_MIN;
            return INT_MAX;
        }
        ans = ans * 10 + s[i] - '0';
        i++;
    }
    if(sign) {
        ans *= -1;
    }
    
    // Handle overflow/underflow
    if(ans > INT_MAX) return INT_MAX;
    if(ans < INT_MIN) return INT_MIN;
    return (int)ans;
}

int main()
{
    char arr[20] = "20000000000000000000";

    printf("%d\n",myAtoi(arr));

    return 0;
}