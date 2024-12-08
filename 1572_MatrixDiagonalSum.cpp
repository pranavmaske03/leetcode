#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int diagonalSum(vector<vector<int>>& mat) 
        {
            int sum = 0;

            for(int i = 0,m = 0,n = mat.size()-1; i < mat.size(); i++,m++,n--)
            {
                sum += mat[i][i];
                if(m != n) 
                {
                    sum += mat[m][n];
                }
            }
            return sum;
        }
};


int main()
{
    vector<vector<int>> mat = {{1,1,1,1},
              {1,1,1,1},
              {1,1,1,1},
              {1,1,1,1}};

    Solution obj;
    cout<<obj.diagonalSum(mat)<<"\n";

    return 0;
}