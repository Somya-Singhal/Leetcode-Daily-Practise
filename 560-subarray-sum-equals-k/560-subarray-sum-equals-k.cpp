class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        int presum=0,count=0;
        for(int i=0;i<n;i++)
        {
            presum+=nums[i];
            if(presum==k)
               count++;
            if(mp.find(presum-k)!=mp.end())
                count+=mp[presum-k];
            mp[presum]++;
        }
        return count;
    }
};