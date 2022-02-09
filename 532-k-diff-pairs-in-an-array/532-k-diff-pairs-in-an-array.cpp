class Solution {
public:
    int findPairs(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        set<pair<int,int>>s;
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++)
            mp[nums[i]]++;
        for(int i=0;i<n;i++)
        {
                mp[nums[i]]--;
                if(mp[nums[i]]==0)
                    mp.erase(nums[i]);
            int num1=nums[i]+k;
            int num2=nums[i]-k;
            if(s.count(make_pair(num1,nums[i]))==0 && s.count(make_pair(nums[i],num1))==0)
            {
                if(mp.find(num1)!=mp.end())
                {
                     ans++;
                    s.insert(make_pair(nums[i],num1));
                    s.insert(make_pair(num1,nums[i]));
                }
            }
            if(s.count(make_pair(nums[i],num2))==0 && s.count(make_pair(num2,nums[i]))==0)
            {
                
                if(k!=0 && mp.find(num2)!=mp.end())
                {
                    ans++;
                    s.insert(make_pair(nums[i],num2));
                    s.insert(make_pair(num2,nums[i]));
                }
                
            }
            
        }
        return ans;
    }
};