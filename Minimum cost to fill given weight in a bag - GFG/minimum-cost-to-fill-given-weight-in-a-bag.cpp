// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
#include <bits/stdc++.h>
#define INF 1000000
using namespace std;
//Position this line where user code will be pasted.

class Solution{
		

	public:
	int minimumCost(int cost[], int N, int W) 
	{ 
        // Your code goes here
        vector<int>val,wt;
        int s=0;
        for(int i=0;i<N;i++)
        {
            if(cost[i]!=-1)
            {
                val.push_back(cost[i]);
                wt.push_back(i+1);
                s++;
            }
        }
        N=s;
        vector<vector<int>>dp(N+1,vector<int>(W+1,0));
        for(int i=0;i<=W;i++)
        {
            dp[0][i]=INT_MAX;
        }
        dp[0][0]=0;
        for(int i=1;i<=N;i++)
        {
            for(int j=1;j<=W;j++)
            {
                if(wt[i-1]<=j && dp[i][j-wt[i-1]]!=INT_MAX)
                dp[i][j]=min(dp[i][j-wt[i-1]]+val[i-1],dp[i-1][j]);
                else
                dp[i][j]=dp[i-1][j];
            }
        }
        return dp[N][W]==INT_MAX?-1:dp[N][W];
        
   
	} 
};


// { Driver Code Starts.
int main() 
{
   	
   
   	int t;
    cin >> t;
    while (t--)
    {
        int n, w;
        cin >> n >> w;

        int a[n];

        for(int i = 0; i < n; i++)
        	cin >> a[i];

       

	    Solution ob;
	    cout << ob.minimumCost(a, n, w) << "\n";
	     
    }
    return 0;
}  // } Driver Code Ends