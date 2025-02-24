#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int count = 0;
        
        // Iterate through each element in nums1
        for(int i = 0; i < nums1.size(); i++) {
            
            // Iterate through each element in nums2
            for(int j = 0; j < nums2.size(); j++) {
                
                // Check if nums1[i] is divisible by (nums2[j] * k)
                if(nums1[i] % (nums2[j] * k) == 0) {
                    count++; // Increase count if condition is met
                }
            }
        }
        
        return count; // Return the total count of valid pairs
    }
};

int main()
{
    return 0;
}