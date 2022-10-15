class Solution {
public:
    int mod=1e9+7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int>ans,arr;
        for(int i=0;i<32;i++)
        {
            if((n & (1<<i))!=0)
                arr.push_back(1<<i);
        }
        int q=queries.size();
        for(int i=0;i<q;i++)
        {
            int x=queries[i][0],y=queries[i][1];
            long long num=1;
            for(int j=x;j<=y;j++)
               num=(num*arr[j])%mod;
            ans.push_back(num);
        }
        return ans;
    }
};