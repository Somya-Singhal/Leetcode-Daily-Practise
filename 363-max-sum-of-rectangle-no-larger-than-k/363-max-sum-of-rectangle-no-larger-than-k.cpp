class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n=matrix.size();
        int m=matrix[0].size();
        int ans=INT_MIN;
        for(int left=0;left<m;left++)
        {
            vector<int>dp(n);
            for(int right=left;right<m;right++)
            {
                for(int i=0;i<n;i++)
                    dp[i]+=matrix[i][right];
                set<int>s;
                s.insert(0);
                int presum=0;
                for(int i=0;i<n;i++)
                {
                    presum+=dp[i];
                    auto it=s.lower_bound(presum-k);
                    if(it!=s.end())
                        ans=max(ans,presum-*it);
                    s.insert({presum});
                }
            }
        }
        return ans;
    }
};