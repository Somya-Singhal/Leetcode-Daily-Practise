class Solution {
public:
    int maxDepth(string s) {
        // stack<char>st;
        // int n=s.length(),count=0;
        // for(int i=0;i<n;i++)
        // {
        //     if(s[i]=='(')
        //     {
        //         st.push('(');
        //     }
        //     else if(s[i]==')')
        //         st.pop();
        //     count=max(count,(int)st.size());
        // }
        // return count;
        
        int count=0,ans=0;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                count++;
            else if(s[i]==')')
                count--;
            ans=max(ans,count);
        }
        return ans;
    }
};