class Solution {
public:
    
    // int solve(vector<set<int>>& v,int target,int i,int sum,vector<vector<int>>& dp)
    // {
    //     if(i>=v.size())
    //         return abs(sum-target);
    //     if(dp[i][sum]!=INT_MAX)
    //         return dp[i][sum];
    //     for(auto it=begin(v[i]);it!=end(v[i]);it++)
    //     {
    //         dp[i][sum]=min(dp[i][sum],solve(v,target,i+1,sum+*it,dp));
    //         if(dp[i][sum]==0 || sum+*it>target)
    //             break;
    //     }
    //     return dp[i][sum];
    // }
    // int minimizeTheDifference(vector<vector<int>>& mat, int target) {
    //     vector<set<int>>v;
    //     vector<vector<int>>dp(71,vector<int>(4901,INT_MAX));
    //     for(auto &x: mat)
    //     {
    //         v.push_back(set<int>(begin(x),end(x)));
    //     }
    //     return solve(v,target,0,0,dp);
    // }
    
    //using bitset
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        bool bt[70*70+1]={};
        int max_e=0;
        for(auto &x: mat)
        {
            int max_e1=0;
            bool bt1[70*70+1]={};
            for(auto i: unordered_set(begin(x),end(x)))
            {
                for(int j=0;j<=max_e;j++)
                {
                    if(j==max_e || bt[j])
                    {
                        bt1[i+j]=true;
                        max_e1=max(max_e1,i+j);
                    }
                }
            }
            swap(bt,bt1);
            max_e=max_e1;
        }
        int res=INT_MAX;
        for(int i=0;i<=70*70;i++)
        {
            if(bt[i])
                res=min(res,abs(i-target));
        }
        return res;
    }
};