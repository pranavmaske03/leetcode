#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        string longestCommonPrefix(vector<string>& strs) 
        {
            string res = "";
            bool flag = true;

            for(int i = 0; i < strs[0].size(); i++)
            {
                for(int j = 0; j < strs.size()-1; j++)
                {
                    if(strs[j][i] == NULL || strs[j][i] != strs[j+1][i]) {
                        flag = false;
                        break;
                    }
                }
                if(!flag) break;
                res += strs[0][i];
            }
            return res;
        }
};

int main()
{

    return 0;
}