#include<iostream>
#include<string>
using namespace std;

#include <string>
using namespace std;

class Solution {
public:
    bool check(const string& s, int i, int j) {
        while (i < j) {
            if (s[i] != s[j])
                return false;
            ++i, --j;
        }
        return true;
    }

    int expand(string& s, int l, int r) {
        int n = s.size();
        while (l >= 0 && r < n && s[l] == s[r]) {
            l--, r++;
        }
        int res = r - l - 1;
        int i = l - 1, j = r;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--, j++;
        }
        res = max(res, j - i - 1);
        i = l, j = r + 1;
        while (i >= 0 && j < n && s[i] == s[j]) {
            i--, j++;
        }
        res = max(res, j - i - 1);
        return res;
    }

    int almostPalindromic(string& s) {
        int n = s.size(), res = 0;
        if (check(s, 0, n - 1))
            return n;
        for (int i = 0; i < n; i++) {
            res = max(res, expand(s, i, i));
            res = max(res, expand(s, i, i + 1));
        }
        return res;
    }
};

int main()
{
    return 0;
}