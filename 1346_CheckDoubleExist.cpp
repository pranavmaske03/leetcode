#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        bool checkIfExist(vector<int>& arr) 
        {
            for(int i = 0; i < arr.size(); i++)
            {
                for(int j = 0; j < arr.size(); j++)
                {
                    if(arr[i] == 2 * arr[j] && i != j) 
                    {
                        return true;
                    }
                }
            }
            return false;
        }
};

int main()
{
    vector<int> vect{10,2,5,3};
    Solution obj;

    if(obj.checkIfExist(vect)) {
        cout<<"true\n";
    } else {
        cout<<"false\n";
    }

    return 0;
}