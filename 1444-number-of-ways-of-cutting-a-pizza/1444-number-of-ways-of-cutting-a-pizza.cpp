class Solution {
public:
    int mod=1e9+7;
    int dfs(int n,int m,int r,int c,int k,vector<vector<vector<int>>>& dp,vector<vector<int>>& prefix)
    {
        if(prefix[r][c]==0)
            return 0;
        if(k==0)
            return 1;
        if(dp[k][r][c]!=-1)
            return dp[k][r][c];
        int ans=0;
        for(int row=r+1;row<n;row++)
        {
            if(prefix[r][c]-prefix[row][c]>0)
                ans=(ans+dfs(n,m,row,c,k-1,dp,prefix))%mod;
        }
        for(int col=c+1;col<m;col++)
        {
            if(prefix[r][c]-prefix[r][col]>0)
                ans=(ans+dfs(n,m,r,col,k-1,dp,prefix))%mod;
        }
        return dp[k][r][c]=ans;
    }
    int ways(vector<string>& pizza, int k) {
        int n=pizza.size(),m=pizza[0].size();
        vector<vector<int>>prefix(n+1,vector<int>(m+1,0));
        vector<vector<vector<int>>>dp=vector(k,vector(n,vector(m,-1)));
        for(int r=n-1;r>=0;r--)
        {
            for(int c=m-1;c>=0;c--)
            {
                prefix[r][c]=prefix[r][c+1]+prefix[r+1][c]-prefix[r+1][c+1]+(pizza[r][c]=='A'?1:0);
            }
        }
        return dfs(n,m,0,0,k-1,dp,prefix);
    }
};