class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        auto first = lower_bound(nums.begin(), nums.end(), target);
        auto last = upper_bound(nums.begin(), nums.end(), target);

        if(first == nums.end() || *first != target) {
            return {-1, -1};
        }
        return {
            static_cast<int>(first - nums.begin()),
            static_cast<int>(last - nums.begin() - 1)
        };
    }
};
// int firstPosition(vector<int>& nums, int target) {
//     int low = 0, high = nums.size() - 1;
//     int ans = -1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (nums[mid] == target) {
//             ans = mid;
//             high = mid - 1;   // move left
//         }
//         else if (nums[mid] < target) {
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return ans;
// }
// int lastPosition(vector<int>& nums, int target) {
//     int low = 0, high = nums.size() - 1;
//     int ans = -1;
//     while (low <= high) {
//         int mid = low + (high - low) / 2;
//         if (nums[mid] == target) {
//             ans = mid;
//             low = mid + 1;   // move right
//         }
//         else if (nums[mid] < target) {
//             low = mid + 1;
//         }
//         else {
//             high = mid - 1;
//         }
//     }
//     return ans;
// }
// vector<int> searchRange(vector<int>& nums, int target) {
//     int first = firstPosition(nums, target);
//     int last = lastPosition(nums, target);
//     return {first, last};
// }