class Solution {
public:
    string reverseWords(string s) {
        stack<string>st;
        string res="";
        int n=s.length();
        string str="";
        for(int i=0;i<n;i++)
        {
            if(s[i]!=' ')
            {
                str+=s[i];
                continue;
            }
            else
            {
                
                if(str.length()>0)
                {
                    st.push(str);
                     st.push("#");
                }   
                str="";
            }
        }
        if(str.length()>0)
        {
            st.push(str);
        }
        else
            st.pop();
        while(!st.empty())
        {
            string t=st.top();
            st.pop();
            if(t!="#")
                res+=t;
            else
                res+=" ";
        }
        return res;
    }
};