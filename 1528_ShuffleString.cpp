#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        string restoreString(string s, vector<int>& indices) 
        {
            vector<char> result(indices.size(),'\0');

            for(int i = 0; i < indices.size(); i++) 
            {
                result[indices[i]] = s[i];
            }
            string str(result.begin(), result.end());
            return str;
        }
};

int main()
{

    return 0;
}