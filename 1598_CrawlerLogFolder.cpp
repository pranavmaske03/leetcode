#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution 
{
    public:
        int minOperations(vector<string>& logs) 
        {
            int count = 0;

            for(auto& log : logs) {
                if(log == "../") {
                    if(count) count--;
                } else if(log == "./") {
                    continue;
                } else {
                    count++;
                }
            }
            return count;
        }
};

int main()
{
    return 0;
}