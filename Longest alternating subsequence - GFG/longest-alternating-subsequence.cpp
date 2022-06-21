// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
class Solution {
	public:
		int AlternatingaMaxLength(vector<int>&nums){
		    // Code here
		  //  int n=nums.size();
		  //  vector<vector<int>>dp(2,vector<int>(n,0));
		  //  dp[0][0]=1,dp[1][0]=1;
		  //  for(int i=1;i<n;i++)
		  //  {
		  //      for(int j=i-1;j>=0;j--)
		  //      {
		  //          if(nums[i]>nums[j])
		  //          dp[0][i]=max(dp[1][j]+1,dp[0][i]);
		  //          if(nums[i]<nums[j])
		  //          dp[1][i]=max(dp[0][j]+1,dp[1][i]);
		  //      }
		  //  }
		  //  int ans=0;
		  //  for(int i=0;i<n;i++)
		  //  {
		  //      ans=max(ans,max(dp[0][i],dp[1][i]));
		  //  }
		  //  return ans;
		  
		  int n=nums.size();
		  int inc=1,desc=1;
		  for(int i=1;i<n;i++)
		  {
		      if(nums[i]>nums[i-1])
		      inc=desc+1;
		      if(nums[i]<nums[i-1])
		      desc=inc+1;
		  }
		  return max(inc,desc);
		}

};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n;
		cin >> n;
		vector<int>nums(n);
		for(int i = 0; i < n; i++)
			cin >> nums[i];
		Solution obj;
		int ans = obj.AlternatingaMaxLength(nums);
		cout << ans << "\n";
	}
	return 0;
}  // } Driver Code Ends