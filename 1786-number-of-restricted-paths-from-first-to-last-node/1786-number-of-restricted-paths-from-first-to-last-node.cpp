class Solution {
public:
    int mod=1e9+7;
      int dfs(int src,int end,vector<vector<pair<int,int>>>& adj,vector<int>& dist,vector<int>& memo)
        {
          if(memo[src]!=-1)
              return memo[src];
            if(src==end)
                return 1;
           int ans=0;
            for(auto x: adj[src])
            {
                if(dist[x.first]<dist[src])
                   ans=(ans+dfs(x.first,end,adj,dist,memo))%mod;
            }
             return memo[src]=ans;
       }
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        for(auto &x: edges)
        {
            adj[x[0]-1].push_back({x[1]-1,x[2]});
            adj[x[1]-1].push_back({x[0]-1,x[2]});
        }
        vector<int>dist(n,INT_MAX);
        dist[n-1]=0;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        // vector<bool>vis(n,false);
        pq.push({0,n-1});
        while(!pq.empty())
        {
            int wt=pq.top().first;
            int node=pq.top().second;
            // vis[node]=true;
            pq.pop();
            if(wt!=dist[node])
                continue;
            for(auto &x: adj[node])
            {
                
                    if(wt+x.second<dist[x.first])
                    {
                        dist[x.first]=wt+x.second;
                        pq.push({dist[x.first],x.first});
                    }
                
            }
        }
        // for(int i=0;i<n;i++)
        //     cout<<dist[i]<<" ";
        // cout<<endl;
        vector<int>memo(n,-1);
        return dfs(0,n-1,adj,dist,memo); 
    }
};