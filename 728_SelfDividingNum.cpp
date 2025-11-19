#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isSelfDividing(int num)
        {
            int temp = num;
            while(temp != 0)
            {
                int digit = temp % 10;
                if(digit == 0) return false;
                if(num % digit != 0) return false;
                temp /= 10;
            }
            return true;
        }

        vector<int> selfDividingNumbers(int left, int right) 
        {
            vector<int> res;
            while(left <= right)
            {
                if(isSelfDividing(left)) {
                    res.push_back(left);
                }
                left++;
            }
            return res;
        }
};

int main()
{

    return 0;
}