class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>s;
        int ans=0;
        for(int i=0;i<n;i++)
            s.insert(nums[i]);
        for(int i=0;i<n;i++)
        {
            if(s.find(nums[i]-1)==s.end())
            {
                int count=1,val=nums[i]+1;
                while(s.find(val)!=s.end())
                {
                     count+=1;
                     val+=1;
                }
                   
                ans=max(count,ans);
            } 
        }
        return ans;
    }
};