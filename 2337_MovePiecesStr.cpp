#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool canChange(string start, string target) 
        {
            const int n = start.size();

            for(int i = 0, j = 0; i < n || j < n; i++,j++)
            {
                // Iterate until 'L' or 'R' not found
                while(i < n && start[i] == '_') i++;
                while(j < n && target[j] == '_') j++;

                char c = start[i];
                if(c != target[j]) return false;
                if(c == 'L' && i < j) return false;
                if(c == 'R' && i > j) return false;
            }
            return true;
        }
};

int main()
{
    string str1 = "_L__R__R_",str2 = "L______RR";

    Solution obj;
    cout<<obj.canChange(str1,str2)<<"\n";

    return 0;
}