class Solution {
public:
    // void dfs(int src,int dst,int k,vector<vector<pair<int,int>>>& adj,vector<bool>& vis,int &fare,int totalcost)
    // {
    //     if(k<-1)
    //        return;
    //     if(src==dst)
    //     {
    //          fare=min(fare,totalcost); 
    //          return;
    //     }
    //     vis[src]=true;
    //     for(auto x:adj[src])
    //     {
    //         int v=x.first;
    //         int wt=x.second;
    //         if(!vis[v] && totalcost+wt<=fare)
    //         {
    //             dfs(v,dst,k-1,adj,vis,fare,totalcost+wt);
    //         }
    //     }
    //     vis[src]=false;
    // }
    // int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
    //     vector<bool>vis(n,false);
    //     for(auto x:flights)
    //     {
    //         int u=x[0];
    //         int v=x[1];
    //         int wt=x[2];
    //         adj[u].push_back(make_pair(v,wt));
    //     }
    //     int fare=INT_MAX;
    //     dfs(src,dst,k,adj,vis,fare,0);
    //     if(fare==INT_MAX)
    //         return -1;
    //     return fare;
    // }
    
    //Bellmann Ford as k stops are also mentioned so it will be more easier
     int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        vector<int>dist(n,INT_MAX); 
        for(auto x:flights)
        {
            int u=x[0];
            int v=x[1];
            int wt=x[2];
            adj[u].push_back(make_pair(v,wt));
        }
         dist[src]=0;
        for(int i=0;i<k+1;i++)
        {
            vector<int>temp=dist;
            for(auto x:flights)
            {
                if(dist[x[0]]==INT_MAX)
                    continue;
                if(temp[x[1]]>dist[x[0]]+x[2])
                    temp[x[1]]=dist[x[0]]+x[2];
            }
            dist=temp;
        }
         return dist[dst]==INT_MAX?-1:dist[dst];
    }
};