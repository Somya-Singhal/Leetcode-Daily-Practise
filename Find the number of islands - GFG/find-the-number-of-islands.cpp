// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    int dx[8]={-1,-1,0,1,1,1,0,-1};
    int dy[8]={0,1,1,1,0,-1,-1,-1};
    bool valid(int x,int y,vector<vector<char>>& grid)
    {
        int r=grid.size(),c=grid[0].size();
        return (x>=0 && x<r && y>=0 && y<c && grid[x][y]=='1');
    }
    void dfs(int i,int j,vector<vector<char>>& grid,vector<vector<bool>>& vis)
    {
        vis[i][j]=true;
        for(int k=0;k<8;k++)
        {
            int newx=i+dx[k],newy=j+dy[k];
            if(valid(newx,newy,grid) && !vis[newx][newy])
            {
                vis[newx][newy]=true;
                dfs(newx,newy,grid,vis);
            }
        }
    }
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int r=grid.size(),c=grid[0].size();
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        int count=0;
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]=='1' && !vis[i][j])
                {
                    count++;
                    dfs(i,j,grid,vis);
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}  // } Driver Code Ends