// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find minimum time required to rot all oranges.
    int dx[4]={-1,0,1,0},dy[4]={0,1,0,-1};
    bool valid(int x,int y,vector<vector<int>>& grid)
    {
        int r=grid.size(),c=grid[0].size();
        return (x>=0 && x<r && y>=0 && y<c && grid[x][y]==1);
    }
    int orangesRotting(vector<vector<int>>& grid) {
        // Code here
        int r=grid.size(),c=grid[0].size();
        queue<pair<int,int>>q;
        vector<vector<bool>>vis(r,vector<bool>(c,false));
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]==2){
                q.push({i,j});
                vis[i][j]=true;
                }
            }
        }
        int ans=-1;
        while(!q.empty())
        {
            int s=q.size();
            for(int i=0;i<s;i++)
            {
                int tr=q.front().first;
                int tc=q.front().second;
                q.pop();
                for(int k=0;k<4;k++)
                {
                    int newx=tr+dx[k],newy=tc+dy[k];
                    if(valid(newx,newy,grid) && !vis[newx][newy])
                    {
                        q.push({newx,newy});
                        vis[newx][newy]=true;
                    }
                }
            }
            ans+=1;
        }
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(grid[i][j]!=0 && vis[i][j]==false)
                return -1;
            }
        }
        return ans;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<int>>grid(n, vector<int>(m, -1));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.orangesRotting(grid);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends