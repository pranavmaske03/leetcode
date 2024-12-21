#include<iostream>
#include<math.h>
using namespace std;

class Solution 
{
    public:
        bool judgeSquareSum(int c) 
        {
            long long sum = 0;
            int left = 0,right = sqrt(c);

            while(left <= right)
            {
                sum = left*left + right*right;
                if(sum == c) {
                    return true;
                }
                else if(sum > c) {
                    right--;
                } else {
                    left++;
                }
            }
            return false;
        }
};

int main()
{
    Solution obj;
    cout<<obj.judgeSquareSum(3);

    return 0;
}