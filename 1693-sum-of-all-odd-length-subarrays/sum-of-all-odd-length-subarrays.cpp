class Solution {
public:
    int sumOddLengthSubarrays(vector<int>& arr) {
        int n = arr.size();
        int totalSum = 0, prefixSum = 0;

        for(int i = 0; i < n; i++) {
            prefixSum += arr[i];

            if((i+1)%2 == 1) {
                int left = 0;
                int right = i + 1;
                int currSum = prefixSum;

                totalSum += currSum;
                while(right < n) {
                    currSum += arr[right++];
                    currSum -= arr[left++];
                    totalSum += currSum;
                }
            }
        }
        return totalSum;
    }
};