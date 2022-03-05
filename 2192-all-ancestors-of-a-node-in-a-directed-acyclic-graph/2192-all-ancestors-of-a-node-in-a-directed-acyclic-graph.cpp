class Solution {
public:
    void dfs(int i,int curr,vector<vector<int>>& adj,vector<int>& vis,vector<vector<int>>& res)
    {
        vis[curr]=1;
        for(auto x:adj[curr])
        {
            if(!vis[x])
            {
                 res[x].push_back(i);
                 dfs(i,x,adj,vis,res);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>>adj(n,vector<int>());
        vector<vector<int>>res(n);
        for(auto &x: edges)
        {
            adj[x[0]].push_back(x[1]);
            // indegree[x[1]]++;
        }
        for(int i=0;i<n;i++)
        {
            vector<int>vis(n);
            dfs(i,i,adj,vis,res);
        }
        return res;
    }
};