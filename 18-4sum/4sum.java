class Solution {
    public List<List<Integer>> fourSum(int[] nums, int target) {
        int n = nums.length;
        List<List<Integer>> res = new ArrayList<>();
        Arrays.sort(nums)       ;

        for(int i = 0; i <= n-4; i++) {
            if(i > 0 && nums[i] == nums[i - 1])
                continue;

            for(int j = i+1; j <= n-3; j++) {
                if(j > (i+1) && nums[j] == nums[j-1])
                    continue;
                
                int k = j + 1;
                int l = n - 1;

                while(k < l) {
                    long sum = (long) nums[i] + nums[j] + nums[k] + nums[l];

                    if(sum == target) {
                        res.add(Arrays.asList(nums[i],nums[j],nums[k],nums[l]));

                        while(k < l && nums[k] == nums[k+1]) 
                            k++;
                        while(l > k&& nums[l] == nums[l-1])
                            l--;
                        
                        k++;
                        l--;
                    } else if(sum < target){
                        k++;
                    } else {
                        l--;
                    }
                }
            }
        }
        return res;
    }
}