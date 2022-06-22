// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

//Function to find the maximum possible amount of money we can win.
class Solution{
    public:
    
    long long maximumAmount(int arr[], int n){
        // Your code here
        vector<vector<int>>dp(n,vector<int>(n,0));
        for(int i=0;i<n;i++)
        {
            dp[i][i]=arr[i];
        }
        for(int gap=0;gap<n;gap++)
        {
            for(int i=0,j=gap;j<n;i++,j++)
            {
                int x=(i+2)<=j?dp[i+2][j]:0;
                int y=(i+1)<=(j-1)?dp[i+1][j-1]:0;
                int z=i<=(j-2)?dp[i][j-2]:0;
                dp[i][j]=max(arr[i]+min(x,y),arr[j]+min(y,z));
            }
        }
        return dp[0][n-1];
    }
};

// { Driver Code Starts.
int main() 
{
   
   	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i=0;i<n;i++)
		cin>>a[i];
		Solution ob;
		cout<< ob.maximumAmount(a,n)<<endl;
	}
	return 0;
}  // } Driver Code Ends