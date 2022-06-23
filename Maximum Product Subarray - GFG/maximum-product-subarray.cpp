// { Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

 // } Driver Code Ends
//User function template for C++
class Solution{
public:

	// Function to find maximum product subarray
	long long maxProduct(vector<int> arr, int n) {
	    // code here
	    long long currmin=arr[0],currmax=arr[0],res=arr[0];
	    for(int i=1;i<n;i++)
	    {
	        long long num=arr[i];
	        if(arr[i]<0)
	        swap(currmin,currmax);
	        if(arr[i]==0)
	        {
	            currmin=1,currmax=1;
	        }
	        currmin=min(num,num*currmin);
	        currmax=max(num,num*currmax);
	        res=max(res,currmax);
	    }
	    
	    return res;
	}
};

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        vector<int> arr(n);
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        Solution ob;
        auto ans = ob.maxProduct(arr, n);
        cout << ans << "\n";
    }
    return 0;
}  // } Driver Code Ends