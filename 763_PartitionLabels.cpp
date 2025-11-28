#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<int> partitionLabels(string s) 
        {
            vector<int> last(26,0);
            int start = 0,end = 0;
            vector<int> ans;

            for(int i = 0; i < s.length(); i++) {
                char c = s[i];
                last[c - 'a'] = i;
            }

            for(int i = 0; i < s.length(); i++)
            {
                char c = s[i];
                end = max(end,last[c - 'a']);
                if(i == end) {
                    ans.push_back(end - start + 1);
                    start = i + 1;
                }                
            }
            return ans;
        }
};

int main()
{

    return 0;
}
