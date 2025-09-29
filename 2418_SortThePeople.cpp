#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<string> sortPeople(vector<string>& names, vector<int>& heights) 
        {
            int n = names.size();
            vector<int> pos(n);

            for(int i = 0; i < n; i++) {
                pos[i] = i;
            }

            sort(pos.begin(), pos.end(), [&heights] (int a, int b) {return heights[a] > heights[b];});

            vector<string> ans(n);
            for(int i = 0; i < n; i++)
            {
                ans[i] = names[pos[i]];
            }
            return ans;
        }
        vector<string> sortPeople1(vector<string>& names, vector<int>& heights) 
        {
            int n = names.size();
            vector<pair<int, string>> people;

            for (int i = 0; i < n; i++) {
                people.push_back({heights[i], names[i]});
            }

            sort(people.begin(), people.end(), [](auto &a, auto &b) {
                return a.first > b.first;
            });

            for(int i = 0; i < n; i++) 
            {
                names[i] = people[i].second;
            }
            return names;
        }
};

int main()
{

    return 0;
}