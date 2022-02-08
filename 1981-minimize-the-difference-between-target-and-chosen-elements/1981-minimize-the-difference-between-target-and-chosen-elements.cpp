class Solution {
public:
    
    int solve(vector<set<int>>& v,int target,int i,int sum,vector<vector<int>>& dp)
    {
        if(i>=v.size())
            return abs(sum-target);
        if(dp[i][sum]!=INT_MAX)
            return dp[i][sum];
        for(auto it=begin(v[i]);it!=end(v[i]);it++)
        {
            dp[i][sum]=min(dp[i][sum],solve(v,target,i+1,sum+*it,dp));
            if(dp[i][sum]==0 || sum+*it>target)
                break;
        }
        return dp[i][sum];
    }
    int minimizeTheDifference(vector<vector<int>>& mat, int target) {
        vector<set<int>>v;
        vector<vector<int>>dp(71,vector<int>(4901,INT_MAX));
        for(auto &x: mat)
        {
            v.push_back(set<int>(begin(x),end(x)));
        }
        return solve(v,target,0,0,dp);
    }
};