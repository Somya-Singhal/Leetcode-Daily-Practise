class Solution {
public:
    bool isValid(string s) {
       stack<char>st;
       if(s[0]==']' || s[0]=='}' || s[0]==')')
           return false;
        st.push(s[0]);
        for(int i=1;i<s.length();i++)
        {
            if(s[i]=='(' || s[i]=='{' || s[i]=='[')
               st.push(s[i]);
            else
            {
                if(st.empty() || (s[i]==')' && st.top()!='(') || (s[i]=='}' && st.top()!='{') || (s[i]==']' && st.top()!='['))
                    return false;
                else
                    st.pop();
            }
        }
        return st.empty();
    }
};