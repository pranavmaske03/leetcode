#include<iostream>

using namespace std;

class Solution {
public:
    bool isBalanced(string num) 
    {
        int sum = 0;

        for(int i = 0; num[i] != '\0'; i++) 
        {
            sum += (i%2 == 0) ? num[i] - '0' : -(num[i] - '0');
        }
        return sum == 0;
    }
};

int main()
{
    string str = "24123";
    Solution obj;
    obj.isBalanced(str);

    return 0;
}