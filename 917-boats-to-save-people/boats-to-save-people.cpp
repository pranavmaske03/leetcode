class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        vector<int> count(limit+1, 0);
        int n = people.size();

        for(int i = 0; i < n; i++) {
            count[people[i]]++;
        }

        int left = 0;
        int right = limit;
        int min_boats = 0;
        while(left <= right) {
            if(count[left] <= 0) {
                left++; continue;
            }
            if(count[right] <= 0) {
                right--; continue;
            } 
            if(left + right <= limit) {
                count[left]--;
            }
            count[right]--;
            min_boats++;
        }
        return min_boats;
    }
};