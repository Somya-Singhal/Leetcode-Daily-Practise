class Solution {
public:
    vector<int> sumEvenAfterQueries(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int>ans;
        int sum=0;
        int n=nums.size(),q=queries.size();
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2==0)
                sum+=nums[i];
        }
        for(int i=0;i<q;i++)
        {
            int index=queries[i][1];
            int temp=nums[index];
            nums[index]+=queries[i][0];
            if(temp%2==0)
                sum-=temp;
            if(nums[index]%2==0)
            {
                sum+=nums[index];
            }
            ans.push_back(sum);
        }
        return ans;
    }
};