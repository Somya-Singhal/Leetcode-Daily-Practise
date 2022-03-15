class Solution {
public:
    int dirx[4]={0,-1,0,1};
    int diry[4]={-1,0,1,0};
    bool isValid(int i,int j,vector<vector<int>>& grid)
    {
        int row=grid.size(),col=grid[0].size();
        return (i>=0 && i<row && j>=0 && j<col && grid[i][j]!=0);
    }
    int backTrack(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis)
    {
       int maxgold=0;
        int curr=grid[i][j];
        for(int k=0;k<4;k++)
        {
            int newx=i+dirx[k],newy=j+diry[k];
            if(isValid(newx,newy,grid) && !vis[newx][newy])
            {
                vis[newx][newy]=1;
                maxgold=max(maxgold,backTrack(newx,newy,grid,vis));
                vis[newx][newy]=0;
            }
        }
        return maxgold+curr;
    }
    int getMaximumGold(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        int maxGold=0;
        for(int i=0;i<row;i++)
        {
            for(int j=0;j<col;j++)
            {
                if(grid[i][j]!=0)
                {
                    vector<vector<int>>vis(row,vector<int>(col,0));
                    vis[i][j]=1;
                    maxGold=max(maxGold,backTrack(i,j,grid,vis));
                }
            }
        }
        return maxGold;
    }
};