#include<iostream>
using namespace std;

class Solution {
public:
    bool validDigit(int n, int x) {
        bool isFound = false;
        int last = -1;
        while(n != 0) {
            int digit = n % 10;
            if(digit == x) isFound = true;
            last = digit;
            n /= 10;
        }
        return (isFound && last != x);
    }
};

int main() {
    return 0;
}