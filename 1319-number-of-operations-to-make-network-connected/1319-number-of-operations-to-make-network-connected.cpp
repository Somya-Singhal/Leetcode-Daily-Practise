class Solution {
public:
    void dfs(int i,vector<vector<int>>& adj,vector<int>& vis)
    {
        vis[i]=true;
        for(auto x:adj[i])
        {
            if(!vis[x])
            {
                dfs(x,adj,vis);
            }
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<vector<int>>adj(n,vector<int>());
        vector<int>vis(n,0);
        if(connections.size()<n-1)
            return -1;
        for(auto x: connections)
        {
            int u=x[0],v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        int count=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                dfs(i,adj,vis);
                count++;
            }
        }
        return count-1;
    }
};