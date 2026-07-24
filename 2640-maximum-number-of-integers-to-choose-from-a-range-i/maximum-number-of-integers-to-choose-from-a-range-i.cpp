class Solution 
{
    public:
        int maxCount(vector<int>& banned, int n, int maxSum) 
        {
            vector<bool> tracker(n+1,true);
            int sum = 0,count = 0;

            for(auto i : banned)  
                if(i <= n) 
                    tracker[i] = false;    
            
            for(int i = 1; i < tracker.size(); i++)
            {
                if(tracker[i] && (sum += i) <= maxSum) 
                    count++;
            }
            return count;
        }
};