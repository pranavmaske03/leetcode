#include<iostream>
#include<bitset>
using namespace std;

class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), [] (unsigned a, unsigned b) {
            if(bitset<sizeof(int) * 8>(a).count() == bitset<sizeof(int) * 8>(b).count()) 
                return a < b;
            else
                return bitset<sizeof(int) * 8>(a).count() < bitset<sizeof(int) * 8>(b).count();
        });
        return arr;
    }
};

int main()
{
    return 0;
}