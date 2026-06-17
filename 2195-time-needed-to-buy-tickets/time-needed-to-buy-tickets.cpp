class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        queue<pair<int,int>> q;
        int time = 0;

        for(int i = 0; i < tickets.size(); i++) {
            q.push({i, tickets[i]});
        }

        while(!q.empty()) {
            auto [idx, rem_tickets] = q.front();
            q.pop();
            
            rem_tickets--;
            time++;

            if(rem_tickets == 0) {
                if(idx == k) return time;
            } else {
                q.push({idx, rem_tickets});
            }
        }
        return time;
    }
};