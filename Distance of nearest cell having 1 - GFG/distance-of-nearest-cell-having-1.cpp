// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution 
{
    public:
    //Function to find distance of nearest 1 in the grid for each cell.
   
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>res(n,vector<int>(m,INT_MAX));
	    vector<vector<int>>vis(n,vector<int>(m,0));
	    queue<pair<int,int>>q;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==1)
	            {
	                q.push({i,j});
	                vis[i][j]=1;
	                res[i][j]=0;
	            }
	             
	        }
	    }
	    
	    while(!q.empty())
	    {
	        int x=q.front().first;
	        int y=q.front().second;
	        q.pop();
	        int dx[4]={-1,0,1,0};
	        int dy[4]={0,1,0,-1};
	        for(int k=0;k<4;k++)
	        {
	            int newx=x+dx[k],newy=y+dy[k];
	            
	                if(newx>=0 && newx<n && newy>=0 && newy<m && grid[newx][newy]==0 && !vis[newx][newy])
    	            {
    	                
        	           res[newx][newy]=min(res[newx][newy],res[x][y]+1);
        	           vis[newx][newy]=1;
        	           q.push({newx,newy});
    	            }
	        }
	    }
	    return res;
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
		vector<vector<int>> ans = obj.nearest(grid);
		for(auto i: ans){
			for(auto j: i){
				cout << j << " ";
			}
			cout << "\n";
		}
	}
	return 0;
}  // } Driver Code Ends