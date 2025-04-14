//leetcode 1544
//https://leetcode.com/problems/make-the-string-great/description/

class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for (auto c:s)
        {
            if(!st.empty()&&(st.top()==(c-32)||(st.top()-32)==c))
                st.pop();
            else
                st.push(c);
        }
        s="";
        while(!st.empty())
        {
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};