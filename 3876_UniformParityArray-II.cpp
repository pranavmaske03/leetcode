#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        bool isOdd = false;
        int minOdd = INT_MAX;

        for(int& num : nums1) {
            if(num%2 != 0) {
                isOdd = true;
                minOdd = min(minOdd, num);
            }
        }
        if(!isOdd) return true;

        for(int& num : nums1) {
            if(num%2 == 0 && num < minOdd)  {
                return false;
            }
        }
        return true;
    }
};

int main() {
    return 0;
}