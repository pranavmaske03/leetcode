#include<iostream>
#include<vector>

using namespace std;
class Solution 
{
    public:
        // transpose and reverse approach
        void rotate(vector<vector<int>>& matrix) 
        {
            for(int i = 0; i < matrix.size()-1; i++)
            {
                for(int j = i+1; j < matrix[i].size(); j++)
                {
                    swap(matrix[i][j],matrix[j][i]);
                }
            }
            for(int i = 0; i < matrix.size(); i++)
            {
                reverse(matrix[i].begin(),matrix[i].end());
            }
        }

        // layer by layer approach
        void rotate1(vector<vector<int>>& matrix) 
        {
            int n = matrix.size();

            // (left → top → right → bottom → left,) ex. ([0,0] -> [0,2] -> [2,2] -> [2,0] -> [0,0])
            for(int layer = 0; layer < n/2; layer++) 
            {
                int first = layer;
                int last = n - 1 - layer;

                for(int i = first; i < last; i++)
                {
                    int offset = i - first;

                    int top = matrix[first][i]; // store top
                    matrix[first][i] = matrix[last - offset][first];   //  left -> top
                    matrix[last - offset][first] = matrix[last][last - offset]; //  bottom -> left
                    matrix[last][last - offset] = matrix[i][last]; // right -> bottom
                    matrix[i][last] = top; // top -> right
                }
            }
        }
};

int main()
{
    vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};
    Solution obj;
    obj.rotate(matrix);

    return 0;
}