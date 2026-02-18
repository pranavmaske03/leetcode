#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> toggleLightBulbs(vector<int>& bulbs) {
        vector<int> res;
        vector<bool> toggle(101, false);

        for(int& bulb : bulbs) {
            toggle[bulb] = !toggle[bulb];
        }
        for(int i = 0; i < toggle.size(); i++) {
            if(toggle[i]) res.push_back(i);
        }
        return res;
    }
};

int main()
{
    return 0;
}