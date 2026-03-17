#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqueEven(vector<int>& nums) {
        vector<int> freq(101, 0);

        for (int& num : nums) {
            if (num % 2 == 0)
                freq[num]++;
        }
        for (int& num : nums) {
            if (num % 2 == 0 && freq[num] == 1)
                return num;
        }
        return -1;
    }
};

int main()
{
    return 0;
}