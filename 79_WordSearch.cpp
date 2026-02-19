#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int row = board.size();
        int col = board[0].size();

        auto dfs = [&] (int i, int j, int k, auto& dfs) -> bool {
            if(k == word.length()) return true;

            if(i < 0 || i >= row || j < 0 || j >= col || board[i][j] != word[k]) {
                return false;
            }

            char temp = board[i][j];
            board[i][j] = '#';

            bool isFound =  dfs(i - 1, j, k + 1, dfs) || 
                            dfs(i + 1, j, k + 1, dfs) || 
                            dfs(i, j + 1, k + 1, dfs) || 
                            dfs(i, j - 1, k + 1, dfs);

            board[i][j] = temp;
            return isFound;
        };

        vector<int> freq(128, 0);
        for (auto& row : board) {
            for (char c : row)
                freq[c]++;
        }
        for (char c : word) {
            if (--freq[c] < 0)
                return false;
        }
        if (freq[word[0]] > freq[word.back()]) {
            reverse(word.begin(), word.end());
        }

        for(int i = 0; i < row; i++) {
            for(int j = 0; j < col; j++) {
                if(board[i][j] == word[0] && dfs(i, j, 0, dfs)) {
                    return true;
                }
            }
        }
        return false;
    }
}; 

int main()
{
    return 0;
}