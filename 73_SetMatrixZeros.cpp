#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        void setZeroes(vector<vector<int>>& matrix) 
        {
            int m = matrix.size(),n = matrix[0].size();
            bool hasColZero = false;

            // mark the col and row zero
            for(int i = 0; i < m; i++)
            {
                if(matrix[i][0] == 0) hasColZero = true;
                for(int j = 1; j < n; j++)
                {
                    if(matrix[i][j] == 0) {
                        matrix[i][0] = 0; // mark col zero
                        matrix[0][j] = 0; // mark row zro
                    }
                }
            }

            // set zeros based on markers
            for(int i = 1; i < m; i++)
            {
                for(int j = 1; j < n; j++)
                {
                    if( matrix[i][0] == 0 ||  matrix[0][j] == 0) {
                        matrix[i][j] = 0;
                    }
                }
            }

            // if first element is zero
            if(matrix[0][0] == 0) {
                for(int i = 0; i < n; i++) matrix[0][i] = 0;
            }

            if(hasColZero) {
                for(int i = 0; i < m; i++) matrix[i][0] = 0;
            }
        }
};

int main()
{

    return 0;
}