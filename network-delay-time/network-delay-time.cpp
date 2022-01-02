class Solution {
public:
    void dfs(int src,vector<vector<pair<int,int>>>& adj,vector<int>& dist)
    {
        for(auto x:adj[src])
        {
            if(dist[x.first]>dist[src]+x.second)
            {
                dist[x.first]=dist[src]+x.second;
                dfs(x.first,adj,dist);
            }
        }
        return;
    }
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int,int>>>adj(n+1,vector<pair<int,int>>());
        vector<int>dist(n+1,INT_MAX);
        for(auto x:times)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            adj[u].push_back(make_pair(v,wt));
        }
        dist[k]=0;
        dfs(k,adj,dist);
        int maxans=0;
        for(int i=1;i<=n;i++)
        {
            if(dist[i]==INT_MAX)
                return -1;
            else
             maxans=max(maxans,dist[i]);   
        }
        return maxans;
    }
};