#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        vector<int> s1_freq(26, 0);
        vector<int> window_freq(26, 0);

        for (char& ch : s1)
            s1_freq[ch - 'a']++;

        int k = s1.size();
        int left = 0;
        for (int right = 0; right < s2.size(); right++) {
            char ch = s2[right];
            window_freq[ch - 'a']++;

            if (right - left + 1 > k)
                window_freq[s2[left++] - 'a']--;

            if (s1_freq == window_freq)
                return true;
        }
        return false;
    }
};

int main()
{
    return 0;
}