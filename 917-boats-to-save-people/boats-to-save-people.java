class Solution {
    public int numRescueBoats(int[] people, int limit) {
        int n = people.length;
        Arrays.sort(people);
        int left = 0, right = n - 1;
        int res = 0;

        while(left <= right) {
            if(people[left] + people[right] <= limit) {
                res++;
                left++;
                right--;
            } else {
                res++;
                right--;
            }
        }
        return res;
    }
}