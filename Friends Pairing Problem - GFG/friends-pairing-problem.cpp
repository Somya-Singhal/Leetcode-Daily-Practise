// { Driver Code Starts
#include <bits/stdc++.h> 
using namespace std; 

 // } Driver Code Ends
class Solution
{
public:
int mod=1e9+7;
// int solve(int n)
// {
//     if(n==0)
//     return 1;
//     if(n>1)
//     return (n-1)*solve(n-2)+solve(n-1);
//     return solve(n-1);
// }
    int countFriendsPairings(int n) 
    { 
        // code here
        // return solve(n);
        vector<long>dp(n+1,0);
        
        for(int i=0;i<=n;i++)
        {
            if(i<=2)
            dp[i]=i;
            else
            dp[i]=(i-1)*dp[i-2]+dp[i-1];
            dp[i]=dp[i]%mod;
        }
        return dp[n]%mod;
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
    	Solution ob;
    	cout <<ob.countFriendsPairings(n); 
    	cout<<endl;
    }
} 
  // } Driver Code Ends