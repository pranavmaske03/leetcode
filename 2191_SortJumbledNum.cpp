#include<iostream>

class Solution {
public:
    // Function to get the mapped value of a number based on the given mapping
    int getMappedValue(vector<int>& mapping, int num) {
        int mappedValue = 0;
        int place = 1;
        if (num == 0) {
            return mapping[0];
        }
        while (num > 0) {
            int digit = num % 10;
            mappedValue += (place * mapping[digit]);
            num /= 10;
            place *= 10;
        }
        return mappedValue;
    }

    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<int> result;
        vector<pair<int, int>> mappedValuesWithIndex;

        // Create a vector of pairs containing mapped values and their original indices
        for (int i = 0; i < nums.size(); i++) {
            int mappedValue = getMappedValue(mapping, nums[i]);
            mappedValuesWithIndex.push_back({mappedValue, i});
        }

        sort(mappedValuesWithIndex.begin(), mappedValuesWithIndex.end());

        // Construct the result vector based on the sorted mapped values and their original indices
        for (const auto& pair : mappedValuesWithIndex) {
            result.push_back(nums[pair.second]);
        }

        return result;
    }
};

int main()
{

    return 0;
}