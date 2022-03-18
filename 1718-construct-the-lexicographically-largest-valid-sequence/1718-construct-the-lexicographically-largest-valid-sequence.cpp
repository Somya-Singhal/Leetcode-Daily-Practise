class Solution {
public:
    vector<int>solve(int idx,int n,vector<int>& ans,vector<int>& vis) {
        if(idx==ans.size())
            return ans;
        if(ans[idx]!=0)
            return solve(idx+1,n,ans,vis);
        for(int i=n;i>=1;i--)
        {
            int dist=i==1?0:i;
            if(vis[i]==0 && idx+dist<ans.size() && ans[idx+dist]==0)
            {
                vis[i]=1;
                ans[idx]=i,ans[idx+dist]=i;
                auto res=solve(idx+1,n,ans,vis);
                if(!res.empty())
                    return res;
                vis[i]=0;
                ans[idx]=0,ans[idx+dist]=0;
            }
        }
        return {};
    }
    vector<int> constructDistancedSequence(int n) {
        int len=2*(n-1)+1;
        vector<int>ans(len,0),vis(n+1,0);
        return solve(0,n,ans,vis);
    }
};