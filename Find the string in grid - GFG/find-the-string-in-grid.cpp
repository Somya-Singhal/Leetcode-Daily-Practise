// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
public:
int dx[8]={-1,-1,0,1,1,1,0,-1};
int dy[8]={0,1,1,1,0,-1,-1,-1};
bool istrue(int i,int j,vector<vector<char>>& grid,string &word)
{
     int n=grid.size(),m=grid[0].size();
    
	
	    for(int k=0;k<8;k++)
	    {
	        int t;
	        int newx=i+dx[k];
	        int newy=j+dy[k];
	        for(t=1;t<word.length();t++)
	        {
	            if(newx<0 || newx>=n || newy<0 || newy>=m)
	            break;
	            if(grid[newx][newy]!=word[t])
	            break;
	            newx+=dx[k],newy+=dy[k];
	        }
	        if(t==word.length())
	        return true;
	    }
	 
	return false;
}
	vector<vector<int>>searchWord(vector<vector<char>>grid, string word){
	    // Code here
	    int n=grid.size(),m=grid[0].size();
	    vector<vector<int>>res;
	    set<pair<int,int>>s;
	    for(int i=0;i<n;i++)
	    {
	        for(int j=0;j<m;j++)
	        {
	            if(grid[i][j]==word[0] && istrue(i,j,grid,word))
	            {
	                s.insert({i,j});
	            }
	            
	        }
	    }
	    for(auto x: s)
	    {
	        res.push_back({x.first,x.second});
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
		vector<vector<char>>grid(n, vector<char>(m,'x'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++)
				cin >> grid[i][j];
		}
		string word;
		cin >> word;
		Solution obj;
		vector<vector<int>>ans = obj.searchWord(grid, word);
		for(auto i: ans){
			for(auto j: i)
				cout << j << " ";
			cout << "\n";
		}
		if(ans.size() == 0)
		{
		    cout<<"-1\n";
		}
	}
	return 0;
}  // } Driver Code Ends