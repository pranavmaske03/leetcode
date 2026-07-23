class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        int n = arr.size();
        unordered_set<int> st;

        for(int& num : arr) {
            if(st.find(2 * num) != st.end())
                return true;
            if(num % 2 == 0 && st.find(num / 2) != st.end()) 
                return true;
            
            st.insert(num);
        }
        return false;
    }
};