class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int left = 0, right = people.size() - 1;
        int boat_count = 0;
        while(left <= right) {
            if(people[left] + people[right] <= limit) {
                boat_count++;
                left++,right--;
            } else {
                boat_count++;
                right--;
            }
        }
        return boat_count;
    }
};