#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
private:
    void dfs(int openP, int closeP, string comb, int n, vector<string>& res) {
        if (comb.length() == 2 * n) {
            res.push_back(comb);
            return;
        }
        if (openP < n)
            dfs(openP + 1, closeP, comb + "(", n, res);

        if (closeP < openP)
            dfs(openP, closeP + 1, comb + ")", n, res);
    }

public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        dfs(0, 0, "", n, res);
        return res;
    }
};

int main()
{
    return 0;
}