class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int n = people.length;
        int min_boats = 0;
        int[] count = new int[limit+1];

        for(int val : people) {
            count[val]++;
        }

        int left = 0;
        int right = limit;
        while(left <= right) {
            if(count[left] <= 0) {
                left++;
                continue;
            }

            if(count[right] <= 0) {
                right--;
                continue;
            }

            if(left + right <= limit) {
                count[left]--;
            }
            count[right]--;
            min_boats++;
        }
        return min_boats;
    }
}