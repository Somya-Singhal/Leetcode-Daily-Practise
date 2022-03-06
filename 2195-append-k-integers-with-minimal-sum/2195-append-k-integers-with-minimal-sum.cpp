class Solution {
public:
    long long minimalKSum(vector<int>& nums, int k) {
       sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i++)
            cout<<nums[i]<<" ";
        long long K=k;
        long long count=0,e=K,sum=K*(K+1)/2;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1])
                continue;
            if(nums[i]<=e)
            {
                sum+=(e+1-nums[i]);
                e++;
            }
        }
        return sum;
    }
};