#include<iostream>
using namespace std;

class Solution 
{
    public:
        int maxRepeating(string sequence, string word) 
        {
            int count = 0;
            string current = word;

            while (sequence.find(current) != string::npos) {
                count++;
                current += word;
            }

            return count;
        }
        // Using recursion
        int helper(string seq,string curr,string word)
        {
            if(seq.find(curr) == string::npos) return 0;

            return 1 + helper(seq,curr+word,word);
        }

        int maxRepeating(string sequence, string word) 
        {
            return helper(sequence,word,word);
        }
};

int main()
{

    return 0;
}