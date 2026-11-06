class Solution {
    public int leastInterval(char[] tasks, int n) {
        int[] freq = new int[26];

        for(char task : tasks) {
            freq[task - 'A']++;
        }

        int maxFreq = 0;
        for(int val : freq) {
            maxFreq = Math.max(maxFreq, val);
        }

        int maxCount = 0;
        for(int val : freq) {
            if(maxFreq == val)
                maxCount++;
        }
        
        int result = (maxFreq - 1) * (n + 1) + maxCount;
        return Math.max(tasks.length, result);
    }
}