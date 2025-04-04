#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool canBeEqual(vector<int>& targetArray, vector<int>& currentArray) {
        vector<int> elementCounts(1001, 0);
        int uniqueCount = 0;
        
        for (int i = 0; i < targetArray.size(); i++) {
            if (elementCounts[targetArray[i]]++ == 0) uniqueCount++;
            if (elementCounts[currentArray[i]]-- == 1) uniqueCount--;
        }
        
        return uniqueCount == 0;
    }
};

int main()
{
    vector<int> arr = {1,1,1,0,0,0}, target = {0,0,0,1,1,1};
    Solution obj;
    bool result = obj.canBeEqual(target,arr);
    if(result) {
        cout<<"Equal\n";
    } else {
        cout<<"Not Equal\n";
    }

    return 0;
}