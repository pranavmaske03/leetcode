#include<iostream>

class Solution 
{
    public:
        bool isPowerOfThree(int n,int power = 1) 
        {
            std::cout<<"Hello\n";
            if(n == 1) return true;
            if(n % 3 != 0) return false;
            return isPowerOfThree(n/3);
        }
};

int main()
{
    Solution obj;
    std::cout<<"output : "<<obj.isPowerOfThree(23);
    
    return 0;
}