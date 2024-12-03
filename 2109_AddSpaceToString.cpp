#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        string addSpaces(string s, vector<int>& spaces) 
        {
            vector<char> result(s.length()+spaces.size());
            int s_index = 0,result_index = 0,space_index = 0;

            while(s_index < s.length())
            {
                if(space_index < spaces.size() && spaces[space_index] == s_index)
                {
                    result[result_index++] = ' ';
                    space_index++;
                }
                result[result_index++] = s[s_index++];
            }
            std::string str(result.begin(), result.end());
            cout<<str<<"\n";
            return str;
        }
};

int main()
{
    string s = "spacing";
    vector<int> spaces = {0,1,2,3,4,5,6};

    Solution obj;
    obj.addSpaces(s,spaces);

    return 0;
}