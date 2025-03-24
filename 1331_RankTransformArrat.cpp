#include <iostream>
#include <vector>
#include <algorithm>  // For std::sort

using namespace std;

class Solution 
{
    public:
        vector<int> arrayRankTransform(vector<int>& arr) {
            if (arr.empty()) return {}; 
            
            int n = arr.size();
            vector<pair<int, int>> result; 
            vector<int> ranks(n); 

            for(int i = 0; i < n; i++)
            {
                result.push_back({arr[i], i});
            }

            sort(result.begin(), result.end());

            int rank = 1;
            ranks[result[0].second] = rank;
            for(int i = 1; i < n; i++) 
            {   
                if(result[i].first == result[i-1].first) {
                    ranks[result[i].second] = rank;
                } else {
                    ranks[result[i].second] = ++rank;
                }
            }
            return ranks;
        }
};

int main()
{
    vector<int> arr = {37,12,28,9,100,56,80,5,12};
    Solution obj;
    obj.arrayRankTransform(arr);
    return 0;
}
