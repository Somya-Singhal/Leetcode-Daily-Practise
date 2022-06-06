// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
public:
bool solve(int sum,int n,int arr[])
{
    vector<vector<bool>>dp(n+1,vector<bool>(sum+1,0));
    for(int i=0;i<=sum;i++)
    {
        dp[0][i]=0;
    }
    for(int i=0;i<=n;i++)
    {
        dp[i][0]=1;
    }
   for(int i=1;i<=n;i++)
   {
       for(int j=1;j<=sum;j++)
       {
           if(arr[i-1]<=j)
           dp[i][j]=dp[i-1][j-arr[i-1]] || dp[i-1][j];
           else
           dp[i][j]=dp[i-1][j];
       }
   }
    return dp[n][sum];
}
    int equalPartition(int N, int arr[])
    {
        // code here
        int sum=0;
        for(int i=0;i<N;i++)
        sum+=arr[i];
        if(sum%2)
        return 0;
        return solve(sum/2,N,arr);
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        int arr[N];
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        if(ob.equalPartition(N, arr))
            cout<<"YES\n";
        else
            cout<<"NO\n";
    }
    return 0;
}  // } Driver Code Ends