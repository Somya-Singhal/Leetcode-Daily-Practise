// { Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution {
  public:
  
    int maxProfit(int K, int N, int A[]) {
        // code here
        int dp[K+1][N+1];
        for(int i=0;i<=N;i++)
            dp[0][i]=0;
        for(int i=0;i<=K;i++)
           dp[i][0]=0;
        for(int i=1;i<=K;i++)
        {
            int prevdiff=INT_MIN;
            for(int j=1;j<N;j++)
            {
               prevdiff=max(prevdiff,dp[i-1][j-1]-A[j-1]); 
               dp[i][j]=max(A[j]+prevdiff,dp[i][j-1]);
            }
        }
        return dp[K][N-1];
    }
};

// { Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> K;
        cin >> N;
        int A[N];
        for (int i = 0; i < N; i++) cin >> A[i];

        Solution ob;
        cout << ob.maxProfit(K, N, A) << endl;
    }
    return 0;
}  // } Driver Code Ends