class Solution {
public:
    int mod=1e9+7;
//     unordered_map<string,int>memo;
//     int solve(char prev,int n)
//     {
//         if(n==0)
//             return 1;
//         string str=to_string(prev)+" "+to_string(n);
//         if(memo.find(str)!=memo.end())
//             return memo[str];
//         if(prev=='a')
//             return memo[str]=solve('e',n-1)%mod;
//         if(prev=='e')
//             return memo[str]=(solve('a',n-1)+solve('i',n-1))%mod;
//         if(prev=='i')
//             return memo[str]=((solve('a',n-1)+solve('e',n-1))%mod+(solve('o',n-1)+solve('u',n-1))%mod)%mod;
//         if(prev=='o')
//             return memo[str]=(solve('i',n-1)+solve('u',n-1))%mod;
            
//         return memo[str]=solve('a',n-1)%mod;
    
//     }
//     int countVowelPermutation(int n) {
       
//         return ((((solve('a',n-1)%mod+solve('e',n-1)%mod)%mod+solve('i',n-1)%mod)%mod+solve('o',n-1)%mod)%mod+solve('u',n-1)%mod)%mod;
//     }
    
        int countVowelPermutation(int n) {
        vector<vector<long>>dp(n+1,vector<long>(5,0));
        int ans=0;
            for(int i=0;i<5;i++)
                dp[1][i]=1;
            for(int i=1;i<n;i++)
            {
                dp[i+1][0]=(dp[i][1]+dp[i][2]+dp[i][4])%mod;
                dp[i+1][1]=(dp[i][0]+dp[i][2])%mod;
                dp[i+1][2]=(dp[i][1]+dp[i][3])%mod;
                dp[i+1][3]=(dp[i][2])%mod;
                dp[i+1][4]=(dp[i][2]+dp[i][3])%mod;
            }
            for(int i=0;i<5;i++)
               ans=(ans+dp[n][i])%mod;
            
            return ans;
    }
};