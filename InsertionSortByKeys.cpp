#include<iostream>
#include<vector>
using namespace std;


// Definition for a Pair
// class Pair {
// public:
//     int key;
//     string value;
//
//     Pair(int key, string value) : key(key), value(value) {}
// };


class Solution 
{
    public:
        vector<vector<pair<int, string>>> insertionSort(vector<pair<int, string>>& pairs) 
        {   
            vector<vector<pair<int,string>>> result;

            if(pairs.empty()) {
                return result;
            }

            result.push_back(pairs);

            for(int i = 1; i < pairs.size(); i++) {
                auto key = pairs[i];
                int j = i - 1;

                while(j >= 0 && pairs[j].first > key.first) {
                    pairs[j+1] = pairs[j];
                    j--;
                }
                pairs[j+1] = key;
                result.push_back(pairs);
            }

            for (int i = 0; i < result.size(); i++) {
                cout << "Row " << i << ": ";
                for (const auto& p : result[i]) {
                    cout << "(" << p.first << ", " << p.second << ") ";
                }
                cout << "\n";
            }

            return result;
        }
};

int main()
{
      vector<pair<int, string>> pairs = {
        {5, "apple"},
        {2, "banana"},
        {9, "cherry"}
    };

    Solution obj;
    obj.insertionSort(pairs);

    return 0;
}
