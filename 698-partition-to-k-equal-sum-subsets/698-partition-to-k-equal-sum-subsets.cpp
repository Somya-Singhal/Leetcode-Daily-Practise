class Solution {
public:
    // int n,target;
    // vector<int>vis;
    // bool solve(int k,vector<int>& nums,int currsum=0,int next_idx=0)
    // {
    //     if(k==1)
    //         return true;
    //     if(currsum==target)
    //         return solve(k-1,nums);
    //     for(int i=next_idx;i<n;i++)
    //     {
    //         if(!vis[i] && currsum+nums[i]<=target)
    //         {
    //             vis[i]=1;
    //             if(solve(k,nums,currsum+nums[i],next_idx+1))
    //                 return true;
    //             vis[i]=0;
    //         }
    //     }
    //     return false;
    // }
    // bool canPartitionKSubsets(vector<int>& nums, int k) {
    //     n=nums.size();
    //     int sum=0;
    //     for(int i=0;i<n;i++)
    //         sum+=nums[i];
    //     if(sum%k)
    //       return false;
    //     target=sum/k;
    //     vis.resize(n,0);
    //     sort(nums.begin(),nums.end(),greater<int>());
    //     return solve(k,nums);
    // }
    
    //  int n,target;
    // vector<int>subsets;
    // bool solve(int idx,int k,vector<int>& nums)
    // {
    //     if(idx==nums.size())
    //     {
    //         for(int i=0;i<k;i++)
    //         {
    //             if(subsets[i]!=target)
    //                 return false;
    //         }
    //         return true;
    //     }
    //     for(int i=0;i<k;i++)
    //     {
    //         if(subsets[i]+nums[idx]<=target)
    //         {
    //             subsets[i]+=nums[idx];
    //             if(solve(idx+1,k,nums))
    //                 return true;
    //             subsets[i]-=nums[idx];
    //         }
    //     }
    //     return false;
    // }
    // bool canPartitionKSubsets(vector<int>& nums, int k) {
    //     n=nums.size();
    //     int sum=0;
    //     for(int i=0;i<n;i++)
    //         sum+=nums[i];
    //     if(sum%k)
    //       return false;
    //     target=sum/k;
    //     subsets.resize(k,0);
    //     sort(nums.begin(),nums.end(),greater<int>());
    //     return solve(0,k,nums);
    // }
    
    bool canPartitionKSubsets(vector<int>& nums, int k) {
    if(nums.size() == 0)
			return false;
		
		int n = nums.size();
		//result array
		vector<bool>dp(1<<n,false);
		vector<int>total(1<<n,0);
		dp[0] = true;
		
		int sum = 0;
		for(int num : nums)
			sum += num;
		sort(nums.begin(),nums.end());
		
		if(sum%k != 0) 
			return false;
		sum /= k;
		if(nums[n-1] > sum)
			return false;
		// Loop over power set
		for(int i = 0;i < (1<<n);i++) {
			if(dp[i]) {
				// Loop over each element to find subset
				for(int j = 0;j < n;j++) {
					// set the jth bit 
					int temp = i | (1 << j);
					if(temp != i) {
						// if total sum is less than target store in dp and total array
						if(nums[j] <= (sum- (total[i]%sum))) {
							dp[temp] = true;
							total[temp] = nums[j] + total[i];
						} else
							break;
					}
				}
			}
		}
		return dp[(1<<n) - 1];
    }
};