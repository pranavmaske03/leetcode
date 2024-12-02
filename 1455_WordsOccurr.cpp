#include<iostream>
#include<vector>
#include<sstream>
using namespace std;

class Solution {
    public:
        bool checkString(string word,string searchWord)
        {
            for(int i = 0; i < searchWord.length(); i++) {
                if(searchWord[i] != word[i]) 
                return false;
            }
            return true;
        }

        int isPrefixOfWord(string sentence, string searchWord) 
        {
            std::istringstream iss(sentence);
            int ipos = -1,count = 0;

            do {
                string subs;
                iss >> subs;
                cout << subs << endl;
                count++;
                if(checkString(subs,searchWord))
                {
                    ipos = count;
                    break;
                }
            } while (iss);

            return ipos;
        }
};

int main()
{
    string senten = "i am tired ";
    Solution obj;

    cout<<obj.isPrefixOfWord(senten,"you")<<"\n";

       
    return 0;
}