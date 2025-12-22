#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution 
{
    public:
        int mostFrequentEven(vector<int>& nums) 
        {
            unordered_map<int,int> mp;

            for (int num : nums) {
                if (num % 2 == 0) {
                    mp[num]++;
                }
            }
            if (mp.empty()) return -1;
            
            int min_even = -1;
            int max_freq = 0;
            for (auto& [key, value] : mp) {
                if (value > max_freq || (value == max_freq && key < min_even)) {
                    max_freq = value;
                    min_even = key;
                }
            }
            return min_even;
        }
};


int main()
{
    
    return 0;
}