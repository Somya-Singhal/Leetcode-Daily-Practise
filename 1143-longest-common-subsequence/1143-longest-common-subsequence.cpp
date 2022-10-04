class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n1=text1.length(),n2=text2.length();
        vector<vector<int>>dp(n1+1,vector<int>(n2+1,0));
        int ans=0;
        for(int i=0;i<=n1;i++)
        {
            for(int j=0;j<=n2;j++)
            {
                if(i==0 && j==0)
                    dp[i][j]=0;
                else if(i==0)
                    dp[i][j]=0;
                else if(j==0)
                    dp[i][j]=0;
                else
                {
                    if(text1[i-1]==text2[j-1])
                        dp[i][j]=1+dp[i-1][j-1];
                    else
                        dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
                } 
                ans=max(ans,dp[i][j]);
            }
        }
        return ans;
    }
};