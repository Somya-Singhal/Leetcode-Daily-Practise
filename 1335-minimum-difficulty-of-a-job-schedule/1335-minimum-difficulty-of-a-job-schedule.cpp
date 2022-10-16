class Solution {
public:
    int solve(int i,vector<int>& jobDifficulty, int d,vector<vector<int>>& dp)
    {
        int n=jobDifficulty.size();
        if(d==0 && i==n)
            return 0;
        if(d==0 || i==n)
            return INT_MAX;
        if(dp[i][d]!=-1)
            return dp[i][d];
        int f=jobDifficulty[i];
        int res=INT_MAX;
        for(int k=i;k<n;k++)
        {
            f=max(jobDifficulty[k],f);
            int s=solve(k+1,jobDifficulty,d-1,dp);
            if(s!=INT_MAX)
              res=min(res,f+s);
        }
        return dp[i][d]=res;
    }
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n=jobDifficulty.size();
        vector<vector<int>>dp(n+1,vector<int>(d+1,-1));
        if(n<d)
            return -1;
        return solve(0,jobDifficulty,d,dp);
    }
};