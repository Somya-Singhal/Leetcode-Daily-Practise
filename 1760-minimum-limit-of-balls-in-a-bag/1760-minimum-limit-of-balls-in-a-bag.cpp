class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int n=nums.size(),total_max=INT_MIN,ans=0;
        for(int i=0;i<n;i++)
            total_max=max(total_max,nums[i]);
        long long lo=1,hi=total_max;
        while(lo<=hi){
            long long mid=(lo+hi)/2;
            int count_op=0;
            for(int i=0;i<n;i++)
            {
                count_op+=(nums[i]-1)/mid;
            }
            if(count_op<=maxOperations)
            {
                ans=mid;
                // cout<<ans<<" ";
                hi=mid-1;
            } else{
                lo=mid+1;
            }
        }
        return ans;
    }
};