// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
  public:
//   long long solve(int i,int a[],int n,int s)
//   {
//       if(s==0)
//       return 1;
//       if(i==n)
//       return 0;
//       if(a[i]<=s)
//       return solve(i,a,n,s-a[i])+solve(i+1,a,n,s);
//       return solve(i+1,a,n,s);
//   }
    long long int count(int S[], int m, int n) {

        // code here.
        vector<vector<long long>>dp(m+1,vector<long long>(n+1,0));
        for(int i=0;i<=m;i++)
        dp[i][0]=1;
        for(int i=1;i<=m;i++)
        {
            for(int j=1;j<=n;j++)
            {
                if(S[i-1]<=j)
                {
                    dp[i][j]=dp[i][j-S[i-1]]+dp[i-1][j];
                }
                else
                {
                    dp[i][j]=dp[i-1][j];
                }
            }
        }
        return dp[m][n];
        // vector<vector<int>>dp(m,vector<int>(n+1,0))
        // return solve(0,S,m,n);
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m;
        cin >> n >> m;
        int arr[m];
        for (int i = 0; i < m; i++) cin >> arr[i];
        Solution ob;
        cout << ob.count(arr, m, n) << endl;
    }

    return 0;
}  // } Driver Code Ends