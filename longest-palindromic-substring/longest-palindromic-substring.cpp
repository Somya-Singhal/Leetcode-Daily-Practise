class Solution {
public:
    string longestPalindrome(string s) {
        int len=s.length();
        string ans="";
        bool dp[len][len];
        for(int gap=0;gap<len;gap++)
        {
            for(int i=0,j=gap;j<len;i++,j++)
            {
                if(i==j)
                {
                    dp[i][j]=true;
                    ans=s[i];
                }
                else if(i+1==j && s[i]==s[j])
                {
                    dp[i][j]=true;
                    ans=s.substr(i,gap+1);
                    cout<<ans<<" ";
                }
                else if(s[i]==s[j])
                {
                    dp[i][j]=dp[i+1][j-1];
                    if(dp[i][j]==true)
                        ans=s.substr(i,gap+1);
                }
                else
                {
                    dp[i][j]=false;
                }
            }
        }
        return ans;
    }
};