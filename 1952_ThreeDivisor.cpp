#include<iostream>
using namespace std;

class Solution 
{
public:
    bool isThree(int n) 
    {
        int count = 2;
        for(int i = 2; i <= (n/2); i++)
        {
            if(n % i == 0) count++;
            if(count > 3) break;
        }
        return count == 3;
    }
};

int main()
{
    Solution obj;
    obj.isThree(5);

    return 0;
}