#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

class Solution {
    public:
        vector<vector<int>> merge(vector<vector<int>>& intervals) 
        {
            vector<vector<int>> result;
            int i = 0,j = 0;

            // sort the time by the start time
            sort(intervals.begin(), intervals.end(), [](const vector<int>& a, const vector<int>& b) {
                return a[0] < b[0];
            });

            for(i = 0,j = 0; i < intervals.size(); i++)
            {
                int start = intervals[i][0];
                int end = intervals[i][1];
                
                // check weather current end time is greater than the subsequent start time.
                if(i < intervals.size()-1 && end >= intervals[i+1][0]) 
                {
                    // check how many overlapping times
                    for(j = i+1; j < intervals.size(); j++) 
                    {
                        if(end < intervals[j][1]) end = intervals[j][1];
                        if(j < intervals.size()-1 && end >= intervals[j+1][0]) continue;
                        else break;
                    }
                    i = j;
                }
                result.push_back({start,end});
            }
            return result;
        }
};

int main()
{
    vector<vector<int>> intervals = {{1,4},{0,4}};//,{6,7},{15,18}};
    Solution obj;
    obj.merge(intervals);

    return 0;
}