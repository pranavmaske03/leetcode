class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();

        Arrays.sort(nums);
        for(int i = 0; i < n; i++) {
            
            if(nums[i] > 0)
                break;
            if(i > 0 && nums[i] == nums[i - 1])
                continue;
            if (nums[i] + nums[n - 2] + nums[n - 1] < 0)
                continue;

            int j = i + 1;
            int k = n - 1;

            while(j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if(sum == 0) {
                    res.add(Arrays.asList(nums[i], nums[j], nums[k]));

                    while(j < k && nums[j] == nums[j + 1])
                        j++;
                    while(k > j && nums[k] == nums[k - 1])
                        k--;
                    
                    j++;
                    k--;
                } else if(sum > 0) {
                    k--;
                } else {
                    j++;
                }
            }
        }
        return res;
    }
}