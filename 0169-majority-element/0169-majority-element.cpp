class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n=nums.size();
        int target=n/2;
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
            mp[nums[i]]+=1;
        int ans=-1;
        for(auto &x: mp)
        {
            if(x.second>target)
            {
                ans=x.first;
                break;
            }
        }
        return ans;
    }
};