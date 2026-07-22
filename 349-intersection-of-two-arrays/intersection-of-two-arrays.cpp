class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<bool> check(10001, false);
        vector<int> res;

        for(int i = 0; i < nums1.size(); i++) {
            check[nums1[i]] = true;
        }

        for(int i = 0; i < nums2.size(); i++) {
            if(check[nums2[i]]) {
                res.push_back(nums2[i]);
                check[nums2[i]] = false;
            }
        }

        return res;
    }
};