class Solution {
    public int threeSumMulti(int[] nums, int target) {
        int n = nums.length;
        long res = 0;
        long MOD = 1000000007;

        Arrays.sort(nums);
        HashMap<Integer, Integer> map = new HashMap<>();

        for (int val : nums) {
            map.put(val, map.getOrDefault(val, 0) + 1);
        }

        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int j = i + 1;
            int k = n - 1;

            while (j < k) {
                int sum = nums[i] + nums[j] + nums[k];
                if (sum == target) {

                    int a = nums[i];
                    int b = nums[j];
                    int c = nums[k];

                    if (a != b && b != c) {
                        res += (long) map.get(a) * map.get(b) * map.get(c);
                    } else if (a == b && b != c) {
                        long countA = map.get(a);
                        long countC = map.get(c);
                        res += (countA * (countA - 1) / 2) * countC;
                    } else if (a != b && b == c) {
                        long countB = map.get(b);
                        long countA = map.get(a);
                        res += countA * (countB * (countB - 1) / 2);
                    } else {
                        long count = map.get(a);
                        res += count * (count - 1) * (count - 2) / 6;
                    }

                    while (j < k && nums[j] == b)
                        j++;
                    while (j < k && nums[k] == c)
                        k--;
                } else if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }

        return (int) (res % MOD);
    }
}