#include<iostream>
#include<vector>

class Solution 
{
    public:
        std::vector<int> findThePrefixCommonArray(std::vector<int>& A, std::vector<int>& B) 
        {
            int n = A.size();
            std::vector<int> frequency(n+1,0);
            std::vector<int> result(n,0);

            int common = 0;
            for(int i = 0; i < n; i++) {
                frequency[A[i]]++;
                if(frequency[A[i]] == 2) ++common;
                frequency[B[i]]++;
                if(frequency[B[i]] == 2) ++common;
                result[i] = common;
            }
            return result;
        }
};

int main()
{


    return 0;
}