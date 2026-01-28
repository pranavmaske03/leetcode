#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool isValidSerialization(string preorder) 
        {
            int slot = 1;

            stringstream s(preorder);
            string str;

            while(getline(s, str, ',')) {
                if(str == "#") {
                    slot--;
                } else {
                    slot++;
                }
                if(slot == 0) break;
            }
            if(getline(s,str,',') || slot != 0) return false;
            return true;
        }
};

int main()
{
    return 0;
}