class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<int>len(n,0),cnt(n,0);
        int longest=0,ans=0;
        for(int i=0;i<n;i++)
        {
            len[i]=1,cnt[i]=1;
             for(int j=i-1;j>=0;j--)
             {
                 if(nums[i]>nums[j])
                 {
                     if(len[i]==len[j]+1)
                         cnt[i]+=cnt[j];
                     if(len[i]<len[j]+1)
                     {
                         len[i]=1+len[j];
                         cnt[i]=cnt[j];
                     } 
                 }
             }
            if(longest==len[i])
                ans+=cnt[i];
            if(longest<len[i])
            {
                longest=len[i];
                ans=cnt[i];
            }
        }
        return ans;
        
    }
};