#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int nthUglyNumber(int n) 
        {
            vector<int> ugly(n);
            // set the first ugly number
            ugly[0] = 1;  
            
            // pointers for the multiples of 2,3,5;
            int p1 = 0,p2 = 0,p3 = 0; 
            // initial multiples 
            int next1 = 2,next2 = 3,next3 = 5;

            for(int i = 1; i < ugly.size(); i++) 
            {
                // find the next ugly number
                ugly[i] = min(next1,min(next2,next3));

                // update the pointer for the smallest factor
                if(ugly[i] == next1) {
                    p1++;
                    next1 = ugly[p1] * 2; // get the next multiple of 2;
                }
                if(ugly[i] == next2) {
                    p2++;
                    next2 = ugly[p2] * 3; // get the next multiple of 3;
                }
                if(ugly[i] == next3) {
                    p3++;
                    next3 = ugly[p3] * 5;  // get the next multiple of 5;
                }
            }
            return ugly[n-1];
        }
};

int main()
{
    Solution obj;
    cout<<obj.nthUglyNumber(11)<<endl;

    return 0;
}