class Solution {
public:
    int mod=1e9+7;
    
    int maxProductPath(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long>>Min(n,vector<long>(m)),Max(n,vector<long>(m));
        Min[n-1][m-1]=Max[n-1][m-1]=grid[n-1][m-1];
        for(int i=m-2;i>=0;i--)
           Min[n-1][i]=Max[n-1][i]=Max[n-1][i+1]*grid[n-1][i];
        for(int i=n-2;i>=0;i--)
           Min[i][m-1]=Max[i][m-1]=Max[i+1][m-1]*grid[i][m-1];
        for(int i=n-2;i>=0;i--)
        {
            for(int j=m-2;j>=0;j--)
            {
                if(grid[i][j]>0)
                {
                    Min[i][j]=grid[i][j]*min(Min[i+1][j],Min[i][j+1]);
                    Max[i][j]=grid[i][j]*max(Max[i+1][j],Max[i][j+1]);
                }
                else
                {
                    Min[i][j]=grid[i][j]*max(Max[i+1][j],Max[i][j+1]);
                    Max[i][j]=grid[i][j]*min(Min[i+1][j],Min[i][j+1]);
                }
            }
        }
        return Max[0][0]<0?-1:Max[0][0]%mod;
    }
};