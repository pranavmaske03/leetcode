#include<iostream>
using namespace std;

/** 
 * Forward declaration of guess API.
 * @param  num   your guess
 * @return 	     -1 if num is higher than the picked number
 *			      1 if num is lower than the picked number
 *               otherwise return 0
 * int guess(int num);
 */

class Solution 
{
    public:
        int guessNumber(int n) 
        {
            int low = 1,high = n,pick = 0;

            while(low <= high) {
                pick = low + (high - low) / 2;

                if(!guess(pick)) {
                    return pick;
                } else if(guess(pick) == 1) {
                    low = pick + 1;
                } else {
                    high = pick - 1;
                }
            }
            return -1; 
        }
};

int main()
{

    return 0;
}