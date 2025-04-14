class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto c:s)
        {
            if(!st.empty()&&c>='0'&&c<='9'&&st.top()>=97&&st.top()<=122)
                st.pop();
            else 
                st.push(c);
        }
        s="";
        while(!st.empty()){
            s=st.top()+s;
            st.pop();
        }
        return s;
    }
};