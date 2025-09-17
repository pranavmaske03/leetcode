#include<stdio.h>

int maxScore(char* s) 
{
    int  max_score = 0,ones = 0,zeros = 0;
    
    int i = 0;
    while(s[i] != '\0') 
    {
        if(s[i] == '1') {
            ones++;
        }
    }

    i = 0;
    while(s[i] != '\0') {
        if(s[i] == '1') {
            ones--;
        } else {
            zeros++;
        }
        max_score = max_score > ones + zeros ? max_score : ones + zeros;
    }
    return max_score;
}

int main()
{


    return 0;
}