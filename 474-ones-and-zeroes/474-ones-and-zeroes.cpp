class Solution {
public:
//      int dp[601][101][101];
//     int solve(int i,vector<string>& strs, int m, int n)
//     {
//         int len=strs.size();

//         if(i==len || (m==0 && n==0))
//             return 0;
//         if(dp[i][m][n]!=-1)
//             return dp[i][m][n];
//         int count0=0,count1=0;
        
//         for(int idx=0;idx<strs[i].length();idx++)
//         {
//             if(strs[i][idx]=='0')
//                 count0++;
//             else
//                 count1++;
//         }
        
//         if(count0<=m && count1<=n)
//            return dp[i][m][n]=max(1+solve(i+1,strs,m-count0,n-count1),solve(i+1,strs,m,n)); 
//         return dp[i][m][n]=solve(i+1,strs,m,n);
//     }
    // int findMaxForm(vector<string>& strs, int m, int n) {
    //     memset(dp,-1,sizeof(dp));
    //     return solve(0,strs,m,n);
    // }
    
    int findMaxForm(vector<string>& strs, int m, int n) {
        int len=strs.size();
        
        vector<vector<int>>dp(m+1,vector<int>(n+1));
        for(auto &str: strs)
        {
            int count0=count(str.begin(),str.end(),'0');
            int count1=str.length()-count0;
            for(int i=m;i>=count0;i--)
            {
                for(int j=n;j>=count1;j--)
                {
                    dp[i][j]=max(1+dp[i-count0][j-count1],dp[i][j]);
                }
            }
        }
       return dp[m][n];
    }
};