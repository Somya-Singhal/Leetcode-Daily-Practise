class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int>vis(26,0);
        vector<int>rem(26,0);
        string ans="";
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++)
        {
            rem[s[i]-'a']++;
        }
        for(int i=0;i<n;i++)
        {
            rem[s[i]-'a']--;
            if(vis[s[i]-'a']==1)
                continue;
            while(!st.empty() && s[i]<st.top() && rem[st.top()-'a']!=0)
            {
                vis[st.top()-'a']=0;
                st.pop();
            }
            st.push(s[i]);
            vis[s[i]-'a']=1; 
        }
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};