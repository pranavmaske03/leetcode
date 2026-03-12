#include<iostream>
using namespace std;

class Solution 
{
    public:
        int expand(string &s , int left ,int right)
        {   
            int count = 0;
            while(left >= 0 &&  right < s.size())
            {
                if(s[left] == s[right]) {
                    count++;
                } else {
                    break;
                }
                left--,right++;
            }
            return count;
        }
        int countSubstrings(string s) 
        {
            int totalCount = 0;
            for(int i = 0; i < s.length(); i++)
            {
                totalCount += expand(s , i, i);
                totalCount += expand(s, i, i+1);
            }
            return totalCount;
        }
        
    //  manchar's algoritham
        int countSubstrings(string s) {
        string t = "#";
        for (char c : s) t += c, t += '#';

        int n = t.size();
        vector<int> p(n, 0);
        int center = 0, right = 0;
        int total = 0;

        for (int i = 0; i < n; i++) {
            if (i < right)
                p[i] = min(right - i, p[2 * center - i]);

            while (i - p[i] - 1 >= 0 && i + p[i] + 1 < n &&
                   t[i - p[i] - 1] == t[i + p[i] + 1])
                p[i]++;

            if (i + p[i] > right) {
                center = i;
                right = i + p[i];
            }

            total += (p[i] + 1) / 2; 
        }

        return total;
    }
};

int main()
{

    return 0;
}