// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
    public:
    int maxSumPairWithDifferenceLessThanK(int arr[], int n, int K)
    {
        // Your code goes here   
        // vector<int>dp(n,0);
        // sort(arr,arr+n);
        // for(int i=1;i<n;i++)
        // {
        //     dp[i]=dp[i-1];
        //     if(arr[i]-arr[i-1]<K)
        //     {
        //         if(i>=2)
        //         dp[i]=max(dp[i],dp[i-2]+arr[i]+arr[i-1]);
        //         else
        //         dp[i]=max(dp[i],arr[i]+arr[i-1]);
        //     }
        // }
        // return dp[n-1];
        
        
        sort(arr,arr+n);
        int maxsum=0;
        for(int i=n-1;i>0;i--)
        {
            if(arr[i]-arr[i-1]<K)
            {
                maxsum+=arr[i]+arr[i-1];
                i--;
            }
        }
        return maxsum;
    }
};

// { Driver Code Starts.
int main() {
	int t;
	cin>>t;
	while(t--)
	{
		int N;
		cin>>N;
		int arr[N];
		for(int i=0;i<N;i++)
		cin>>arr[i];

		int K;
		cin>>K;
        Solution ob;
		cout<<ob.maxSumPairWithDifferenceLessThanK(arr,N,K)<<endl;
	}
	return 0;
}
  // } Driver Code Ends