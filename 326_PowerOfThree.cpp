#include<iostream>

class Solution {
public:
    bool isPowerOfThree(int n) 
    {
        int max = INT_MAX;
        long long power = 1;
        if(n == 1) return true;
        while(power < max)
        {
            power *= 3;
            if(power == n) return true;
            if(power > n) break;
        }
        return false;
    }
};

int main()
{
    Solution obj;
    obj.isPowerOfThree(27);
    
    return 0;
}