#include<iostream>
using namespace std;

class Solution 
{
    public:
        int minimumDeletions(string s) 
        {
            int delete_count = 0,count = 0;
            for(int i = 0; i < s.length(); i++) {
                if(s[i] == 'b') {
                    count++;
                } else if(count != 0) {
                    delete_count++;
                    count--;
                }
            }
            return delete_count;
        }
};

int main()
{

    return 0;
}