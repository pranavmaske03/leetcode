#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isToeplitzMatrix(vector<vector<int>>& matrix) 
        {
            for(int i = 0; i < matrix.size() - 1; i++) {
                for(int j = 1; j < matrix[i].size(); j++) {
                    if(matrix[i][j - 1] != matrix[i + 1][j]) return false;
                }
            }
            return true;
        }   
};

int main()
{

    return 0;
}