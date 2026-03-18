#include<iostream>
using namespace std;

class Solution {
public:
    int countCommas(int n) {
        if(n < 1000) return 0;
        else return n - 999;
    }
};

int main()
{
    return 0;
}