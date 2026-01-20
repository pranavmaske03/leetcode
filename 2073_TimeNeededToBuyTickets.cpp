#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        int timeRequiredToBuy(vector<int>& tickets, int k) 
        {
            queue<int> q;
            for(int i = 0; i < tickets.size(); i++) {
                q.push(i);
            }

            int seconds = 0;
            while(!q.empty())               
            {
                int idx = q.front();
                tickets[idx]--;
                seconds++;
                q.pop();

                if(tickets[idx] != 0) q.push(idx);
                if(tickets[k] == 0) break;
            }
            return seconds;
        }
};

int main()
{
    return 0;
}