#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int, int> freq;
        unordered_map<int, int> freq_count;
        for (int num : nums) {
            freq[num]++;
        }
        for (auto& p : freq) {
            freq_count[p.second]++;
        }
        for (int num : nums) {
            int num_freq = freq[num];
            if (freq_count[num_freq] == 1) {
                return num;
            }
        }
        return -1;
    }
};

int main()
{

    return 0;
}