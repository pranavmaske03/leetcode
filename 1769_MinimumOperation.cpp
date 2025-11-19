#include<iostream>
#include<vector>
#include<string>
using namespace std;

class Solution {
public:
    vector<int> minOperations(string boxes) 
    {
        vector<int> filledBox;
        vector<int> result;

        for(int i = 0; i < boxes.length(); i++) 
        {
            if(boxes[i] == '1') {
                filledBox.push_back(i);
            }
        }
        for(int i = 0; i < boxes.length(); i++) 
        {
            int totalOpr = 0;
            for(int j = 0; j < filledBox.size(); j++) 
            {
                if(i != filledBox[j]) 
                {
                    totalOpr += (abs(filledBox[j] - i));
                }
            }
            result.push_back(totalOpr);
        }
        for(auto i : result) {
            cout<<i<<"\t";
        }
        cout<<endl;
        return result;
    }    

    vector<int> minOperations(string boxes) 
    {
        vector<int> ans(boxes.size(),0);
        int ops = 0,balls = 0;

        for(int i = 0; i < boxes.size(); i++) {
            ans[i] += ops;
            if(boxes[i] == '1') balls++;
            ops += balls;
        }

        ops = 0,balls = 0;
        for(int i = boxes.size()-1; i >= 0; i--) {
            ans[i] += ops;
            if(boxes[i] == '1') balls++;
            ops += balls;
        }
        return ans;
    }
};

int main() 
{
    string s = "00000100000000000010";

    Solution obj;
    obj.minOperations(s);

    return 0;
}