class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<pair<int, string>> peoples;

        for(int i = 0; i < names.size(); i++) {
            peoples.push_back({heights[i],names[i]});
        }
        sort(peoples.begin(), peoples.end(), [](auto &a, auto &b) {
            return a.first > b.first;
        });
        for(int i = 0; i < peoples.size(); i++) {
            names[i] = peoples[i].second;
        }

        return names;
    }
};