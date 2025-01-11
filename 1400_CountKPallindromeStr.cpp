#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool canConstruct(string s, int k) {

            if(s.length() < k) return false;
            vector<int> countChar(26,0);
            
            for(int i = 0; i < s.length(); i++) {
                countChar[s[i] - 97]++;
            }
            int countOdd = 0;
            for(int i = 0; i < 26; i++) {
                if(countChar[i] % 2) {
                    countOdd++;
                }
            }
            return countOdd <= k;
        }
};

int main() {

    string s = "leetcode";
    int k = 3;
    
    Solution obj;
    cout<<obj.canConstruct(s,k);

    return 0;
}