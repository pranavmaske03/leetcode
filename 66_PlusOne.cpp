#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> plusOne(vector<int>& digits) 
        {
            int n = digits.size();
            bool flag = false;

            for(int i = n - 1; i >= 0; i--)
            {
                if(digits[i] == 9) {
                    digits[i] = 0;
                    if(i == 0) {
                        flag = true;
                    }
                } else {
                    digits[i]++;
                    break;
                }

                if(flag) {
                    digits[0] = 1;
                    digits.push_back(0);
                }
            }
            return digits;
        }
};

int main()
{

    return 0;
}