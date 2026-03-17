#include<iostream>
using namespace std;

class Solution {
public:
    string getHappyString(int n, int k) {

        int total = 3 * (1 << (n - 1));
        if (k > total)
            return "";

        string ans = "";
        char prev = '#';

        for (int i = 0; i < n; i++) {

            int remaining = n - i - 1;
            int block = 1 << remaining;

            for (char c : {'a', 'b', 'c'}) {
                if (c == prev)
                    continue;
                if (k > block) {
                    k -= block;
                } else {
                    ans += c;
                    prev = c;
                    break;
                }
            }
        }
        return ans;
    }
};

int main()
{
    return 0;
}