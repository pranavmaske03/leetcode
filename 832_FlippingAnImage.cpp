#include<iostream>
#include<vector>
using namespace std;

class Solution 
{
    public:
        vector<vector<int>> flipAndInvertImage(vector<vector<int>>& image) 
        {
            int n = image.size();

            for(int i = 0; i < n; i++)
            {
                int left = 0,right = n-1;
                while(left <= right) {
                    int temp = image[i][left];
                    image[i][left] = !image[i][right];
                    image[i][right] = !temp;
                    left++;
                    right--;
                }
            }
            return image;
        }
};

int main()
{

    return 0;
}