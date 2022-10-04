class Solution {
public:
   
    string longestPalindrome(string s) {
        int n=s.length();
        vector<vector<int>>dp(n,vector<int>(n,0));
        string ans="";
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
               if(gap==0)
               {
                   dp[i][j]=1;
                   ans=s[i];
               }
               else if(gap==1)
               {
                   if(s[i]==s[j])
                   {
                       dp[i][j]=1;
                       ans=s.substr(i,2);
                   }
               }
              else
              {
                  if(s[i]==s[j])
                  {
                      dp[i][j]=dp[i+1][j-1];
                  }
                  if(dp[i][j])
                       ans=s.substr(i,j-i+1);
              }
                   
            }
            
        }
        return ans;
    }
};