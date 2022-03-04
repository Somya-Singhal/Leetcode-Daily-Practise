class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        int n=nums.size();
        deque<long>d;
        vector<long>sum(nums.begin(),nums.end());
        long res=n+1;
        for(long i=0;i<n;i++)
        {
            if(i>0)
                sum[i]+=sum[i-1];
            if(sum[i]>=k)
                res=min(res,i+1);
            while(!d.empty() && sum[i]-sum[d.front()]>=k)
            {
                res=min(res,i-d.front());
                d.pop_front();
            }
            while(!d.empty() && sum[i]<=sum[d.back()])
                d.pop_back();
            d.push_back(i);
        }
        return res<=n?res:-1;
    }
};