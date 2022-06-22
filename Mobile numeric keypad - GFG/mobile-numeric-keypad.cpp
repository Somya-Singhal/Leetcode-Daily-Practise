// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution{


	public:
	int dx[5] = {0,0,-1,0,1};
    int dy[5] = {0,-1,0,1,0};
    long long dp[5][4][26];
	long long solve(int i,int j,char grid[4][3],int n)
	{
	    if(n<=0)
	    return 0;
	    if(n==1)
	    return 1;
	    if(dp[i][j][n]!=-1)
	    return dp[i][j][n];
	    long long ans=0;
	    for(int k=0;k<5;k++)
	    {
	        int newx=i+dx[k];
	        int newy=j+dy[k];
	        if(newx>=0 && newx<4 && newy>=0 && newy<3 && (grid[newx][newy]!='#' && grid[newx][newy]!='*'))
	        {
	            ans+=solve(newx,newy,grid,n-1);
	        }
	    }
	    return dp[i][j][n]=ans;
	}
	long long getCount(int N)
	{
		// Your code goes here
		if(N<=0)
		return 0;
		if(N==1)
		return 10;
		memset(dp,-1,sizeof(dp));
		char grid[4][3]={{'1','2','3'},{'4','5','6'},{'7','8','9'},{'*','0','#'}};
		long long count=0;
		for(int i=0;i<4;i++)
		{
		    for(int j=0;j<3;j++)
		    {
		        if(grid[i][j]!='#' && grid[i][j]!='*')
		        count+=solve(i,j,grid,N);
		    }
		}
		return count;
	}


};

// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;

       

	    Solution ob;
	    cout << ob.getCount(n) << "\n";
	     
    }
    return 0;
}
  // } Driver Code Ends