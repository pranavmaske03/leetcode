#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    struct TrieNode {
        TrieNode* next[26];
        string word;

        TrieNode() {
            for (int i = 0; i < 26; i++) {
                next[i] = nullptr;
            }
        }
    };

public:
    void insert(TrieNode* root, string& word) {
        TrieNode* node = root;
        for (char& ch : word) {
            int i = ch - 'a';
            if (node->next[i] == nullptr)
                node->next[i] = new TrieNode();
            node = node->next[i];
        }
        node->word = word;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        vector<string> res;
        int row = board.size();
        int col = board[0].size();
        TrieNode* root = new TrieNode();

        auto dfs = [&](int i, int j, TrieNode* node, auto& dfs) -> void {
            if (i < 0 || i >= row || j < 0 || j >= col)
                return;
            char ch = board[i][j];

            if (ch == '#' || node->next[ch - 'a'] == nullptr)
                return;

            node = node->next[ch - 'a'];
            if (node->word != "") {
                res.push_back(node->word);
                node->word = "";
            }

            board[i][j] = '#';
            dfs(i + 1, j, node, dfs);
            dfs(i - 1, j, node, dfs);
            dfs(i, j + 1, node, dfs);
            dfs(i, j - 1, node, dfs);
            board[i][j] = ch;
        };

        for (auto& word : words) {
            insert(root, word);
        }
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                dfs(i, j, root, dfs);
            }
        }
        return res;
    }
};

int main()
{
    return 0;
}