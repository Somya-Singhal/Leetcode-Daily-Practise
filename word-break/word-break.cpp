class Solution {
public:
    // recursive-->O(2^n)
    // bool wordbreakrec(int idx,string s,unordered_set<string>& se)
    // {
    //     if(idx==s.length())
    //         return true;
    //     for(int i=idx;i<s.length();i++)
    //     {
    //         if(se.find(s.substr(idx,i-idx+1))!=se.end() && wordbreakrec(i+1,s,se))
    //             return true;
    //     }
    //     return false;
    // }
    // bool wordBreak(string s, vector<string>& wordDict) {
    //     unordered_set<string>se;
    //     for(int i=0;i<wordDict.size();i++)
    //     {
    //         se.insert({wordDict[i]});
    //     }
    //    return wordbreakrec(0,s,se);
    // }
    
//     bool wordBreak(string s, vector<string>& wordDict) {
//         int n=s.length();
//         bool dp[n][n];
//         unordered_set<string>se;
//         for(int i=0;i<wordDict.size();i++)
//         {
//             se.insert({wordDict[i]});
//         }
//         for(int gap=0;gap<n;gap++)
//         {
//            for(int i=0,j=gap;j<n;i++,j++)
//            {
//                if(se.find(s.substr(i,i+gap+1))!=se.end())
//                {
//                    dp[i][j]=true;
//                    break;
//                }
               
//                    for(int k=i;k<j;k++)
//                    {
//                         dp[i][j]=dp[i][k] && dp[k+1][j];
//                         if(dp[i][j]==true)
//                            break;
//                    }         
//            }
//         }
//        return dp[n][n];
//     }
    bool wordbreakrec(int idx,string s,unordered_set<string>& se,vector<int>& dp)
    {
        if(idx==s.length())
            return 1;
         if(dp[idx]!=-1)
            return dp[idx];
        for(int i=idx;i<s.length();i++)
        {
            if(se.find(s.substr(idx,i-idx+1))!=se.end() && wordbreakrec(i+1,s,se,dp))
                return dp[idx]=1;
        }
        return dp[idx]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int n=s.length();
        unordered_set<string>se;
        vector<int>dp(n,-1);
        for(int i=0;i<wordDict.size();i++)
        {
            se.insert({wordDict[i]});
        }
       return wordbreakrec(0,s,se,dp);
    }
};