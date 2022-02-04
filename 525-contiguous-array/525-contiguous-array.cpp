class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n=nums.size();
        int maxlen=0;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            if(nums[i]==0)
                nums[i]=-1;
        }
        int presum=0;
        for(int i=0;i<n;i++)
        {
            presum+=nums[i];
            if(presum==0)
               maxlen=max(maxlen,i+1);
            if(mp.find(presum)!=mp.end())
                maxlen=max(maxlen,i-mp[presum]);
            if(mp.find(presum)==mp.end())
            {
                mp[presum]=i;
            }
        }
        return maxlen;
    }
};