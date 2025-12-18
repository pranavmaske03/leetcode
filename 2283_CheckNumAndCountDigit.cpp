#include<iostream>
using namespace std;

class Solution 
{
    public:
        bool digitCount(string num) 
        {
            vector<int> freq(10,0);

            for(auto& n : num) {
                freq[n - '0']++;
            }

            for(int i = 0; i < num.length(); i++) {
                if(num[i] - '0' != freq[i]) return false;
            }
            return true;
        }
};

int main()
{

    return 0;
}