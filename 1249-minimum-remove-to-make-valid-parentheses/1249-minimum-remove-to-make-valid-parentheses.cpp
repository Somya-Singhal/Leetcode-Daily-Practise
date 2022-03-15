class Solution {
public:
        
    string minRemoveToMakeValid(string s) {
        int n=s.length();
        string str1=s,str2=s;
        stack<int>st;
        for(int i=0;i<n;i++)
        {
           if(s[i]=='(')
               st.push(i);
            if(s[i]==')')
            {
                if(!st.empty())
                    st.pop();
                else
                    s[i]='*';
            }
        }
        while(!st.empty())
        {
            s[st.top()]='*';
            st.pop();
        }
        s.erase(remove(s.begin(),s.end(),'*'),s.end());
        return s;
    }
};