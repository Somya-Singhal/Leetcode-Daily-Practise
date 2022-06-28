// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n=nums.size();
	    pair<int,int>p[n];
	    for(int i=0;i<n;i++)
	    {
	        p[i].first=nums[i];
	        p[i].second=i;
	    }
	    sort(p,p+n);
	    vector<int>vis(n,0);
	    int ans=0;
	    for(int i=0;i<n;i++)
	    {
	        if(vis[i] || p[i].second==i)
	        continue;
	        int j=i,cyclelen=0;
	        while(!vis[j])
	        {
	            vis[j]=true;
	            j=p[j].second;
	            cyclelen++;
	        }
	        if(cyclelen>0)
	        ans+=(cyclelen-1);
	    }
	    return ans;
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
		int ans = obj.minSwaps(nums);
		cout << ans <<"\n";
	}
	return 0;
}  // } Driver Code Ends