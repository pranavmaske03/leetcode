#include<iostream>
#include<vector>
#include<limits.h>

using namespace std;

class Solution 
{
    public:
        long long maxMatrixSum(vector<vector<int>>& matrix) 
        {
            long long totalSum = 0;
            int minabsval = INT_MAX;
            int negativeCount = 0;

            for (auto& row : matrix) 
            {
                for (int val : row) 
                {
                    totalSum += abs(val);
                    if(val < 0)
                    {
                        negativeCount++;
                    }
                    minabsval = min(minabsval,abs(val));
                }
            }
            if(negativeCount % 2 != 0)
            {
                totalSum -= (2 * minabsval);
            }
            return totalSum;
        }
};

int main()
{
    vector<vector<int>> mat = {
        {-1,0,-1},{-2,1,3},{3,2,2}
    };

    Solution obj;
    cout<<obj.maxMatrixSum(mat);

    return 0;
}