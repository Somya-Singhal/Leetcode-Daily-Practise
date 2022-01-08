class Solution {
public:
    //flyod warshall algo
    void dfs(int node,int parent,vector<int>& res,vector<int>& count,vector<vector<int>>& adj)
    {
        for(auto x:adj[node])
        {
            if(x!=parent)
            {
                dfs(x,node,res,count,adj);
                count[node]+=count[x];
                res[node]+=res[x]+count[x];
            }
        }
    }
    void dfs2(int node,int parent,vector<int>& res,vector<int>& count,vector<vector<int>>& adj,int n)
    {
         for(auto x:adj[node])
        {
            if(x!=parent)
            {
                res[x]=res[node]-count[x]+(n-count[x]);
                dfs2(x,node,res,count,adj,n);
            }
        }
    }
    vector<int> sumOfDistancesInTree(int n, vector<vector<int>>& edges) {
    vector<int>res(n,0);
    vector<int>count(n,1);
    vector<vector<int>>adj(n,vector<int>());
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        dfs(0,-1,res,count,adj);
        dfs2(0,-1,res,count,adj,n);
        return res;
    }
};