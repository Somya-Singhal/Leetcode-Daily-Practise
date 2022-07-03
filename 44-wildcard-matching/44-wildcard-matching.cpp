class Solution {
public:
    bool isMatch(string s, string p) {
       int strlen=s.length();
       int pattlen=p.length();
       bool dp[pattlen+1][strlen+1];
       for(int i=0;i<=pattlen;i++)
       {
           for(int j=0;j<=strlen;j++)
           {
               if(i==0 && j==0)
                   dp[i][j]=true;
               else if(i==0)
                   dp[i][j]=false;
               else if(j==0)
               {
                   if(p[i-1]=='*')
                       dp[i][j]=dp[i-1][j];
                   else 
                       dp[i][j]=false;
               }
               else 
               {
                   if(p[i-1]=='*')
                     dp[i][j]=dp[i-1][j] | dp[i][j-1];
                   else if(p[i-1]=='?' || p[i-1]==s[j-1])
                    dp[i][j]=dp[i-1][j-1];
                   else
                       dp[i][j]=false;
               }
           }
       }
        return dp[pattlen][strlen];
    }
};