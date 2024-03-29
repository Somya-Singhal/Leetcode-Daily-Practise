
class Solution {
public:
    int mod=1e9+7;
//     int memo[502][502];
//     int len;
//     int solve(int i,int steps)
//     {
//         if(steps==0 && i==0)
//             return i==0;
//         if(i<0 || i>=len || steps==0 || i>steps)
//             return 0;
//         if(memo[i][steps]!=-1)
//             return memo[i][steps];
//         return memo[i][steps]=((solve(i-1,steps-1)%mod+solve(i+1,steps-1))%mod+solve(i,steps-1))%mod;
        
//     }
//     int numWays(int steps, int arrLen) {
//         memset(memo,-1,sizeof(memo));
//         len=arrLen;
//         return solve(0,steps);
//     }
    
     int numWays(int steps, int arrLen) {
       int len=min(steps/2+1,arrLen);
       vector<vector<int>>dp(steps+1,vector<int>(len+2,0));
       dp[0][1]=1;
       for(int i=1;i<=steps;i++)
       {
           for(int j=1;j<=len;j++)
               dp[i][j]=((dp[i-1][j-1]%mod+dp[i-1][j+1])%mod+dp[i-1][j])%mod;
       }
         return dp[steps][1];
    }
    
    //  int numWays(int steps, int arrLen) {
    //      int len=min(steps/2+1,arrLen);
    //    vector<int>v1(len+2),v2(len+2);
    //    v1[1]=1;
    //    while(steps-->0)
    //    {
    //        for(int j=1;j<=len;j++)
    //        {
    //            v2[j]=((v1[j-1]%mod+v1[j+1])%mod+v1[j])%mod;
    //        }
    //        swap(v1,v2);
    //    }
    //      for(int i=0;i<=len+1;i++)
    //          cout<<v1[i]<<" ";
    //      for(int i=0;i<=len+1;i++)
    //          cout<<v2[i]<<" ";
    //    return v1[1];
    // }
};

    
    