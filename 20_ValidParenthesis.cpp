#include<iostream>
#include<stack>
using namespace std;

class Solution 
{
    public:
        bool isValid(string s) 
        {
            stack<char> st;
            for(auto ch : s) {
                if(ch == '(') {
                    st.push(')');
                } else if(ch == '[') {
                    st.push(']');
                } else if(ch == '{') {
                    st.push('}');
                } else {
                    if(st.empty() || st.top() != ch) {
                        return false;
                    }
                    st.pop();
                }             
            }
            return st.empty();
        }
};

int main()
{

    return 0;
}