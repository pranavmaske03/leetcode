#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& capacity, int itemSize) {
        int minIndex = -1, val = INT_MAX;
        for(int i = 0; i < capacity.size(); i++) {
            if(capacity[i] >= itemSize) {
                if(val > capacity[i]) {
                    val = capacity[i];
                    minIndex = i;
                }
            }
        }
        return minIndex;
    }
};

int main() {
    Solution s;
    vector<int> capacity = {1, 2, 3, 4, 5};
    int itemSize = 3;
    cout << s.minimumIndex(capacity, itemSize) << endl; // Output: 2
    return 0;
}