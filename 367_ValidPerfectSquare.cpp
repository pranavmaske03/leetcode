#include<iostream>
using namespaces std;

class Solution 
{
    public:
        bool isPerfectSquare(int num) 
        {
            if(!num%2) return false;
            long long start = 0,end = num,mid = 0;

            while(start <= end) 
            {
                mid = start + (end - start) / 2;

                if(mid * mid == num) {
                    return true;
                }
                if(mid * mid < num) {
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            return false;
        }
};

int main()
{


    return 0;
}