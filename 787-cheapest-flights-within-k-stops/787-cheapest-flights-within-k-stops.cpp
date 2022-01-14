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
    //time->
    //  int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
    //     vector<int>dist(n,INT_MAX); 
    //      dist[src]=0;
    //      vector<int>temp=dist;
    //     for(int i=0;i<k+1;i++)
    //     {
    //         for(auto x:flights)
    //         {
    //             if(dist[x[0]]==INT_MAX)
    //                 continue;
    //             if(temp[x[1]]>dist[x[0]]+x[2])
    //                 temp[x[1]]=dist[x[0]]+x[2];
    //         }
    //         dist=temp;
    //     }
    //      return dist[dst]==INT_MAX?-1:dist[dst];
    // }
    
    //dijkstra algo
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
         k++;
         list<pair<int,pair<int,int>>>li;
         li.push_back(make_pair(src,make_pair(0,0)));
         int mymin=INT_MAX;
        while(!li.empty())
        {
            int u=li.front().first,step=li.front().second.first,wt=li.front().second.second;
            li.pop_front();
            if(u==dst)
                mymin=min(mymin,wt);
            if(step==k)
                continue;
            step+=1;
            for(auto x:adj[u])
            {
                int v=x.first,wtu=x.second;
                if(dist[v]>wt+wtu)
                {
                      dist[v]=wt+wtu;
                      li.push_back(make_pair(v,make_pair(step,dist[v])));
                }
            }
        }
         return mymin==INT_MAX?-1:mymin;
//      unordered_map<int, vector<pair<int, int>>> mp;
//         for (int i = 0; i < flights.size(); i++) {
//             mp[flights[i][0]].push_back(make_pair(flights[i][1], flights[i][2]));
//         }
//         k += 1;
//         list<pair<int, pair<int, int>>> ver;
//         ver.push_back(make_pair(src, make_pair(0, 0)));
//         vector<int> dp(n, INT_MAX);
//         dp[src] = 0;
//         int mini = INT_MAX;
        
//         while (!ver.empty()) {
//             int u = ver.front().first, steps = ver.front().second.first, w = ver.front().second.second;
//             //cout << u << ":" << w << ":" << steps << endl;
//             ver.pop_front();
//             if (u == dst)   mini = min(mini, w);
//             if (steps == k) continue;
//             steps += 1;
//             for (int i = 0; i < mp[u].size(); i++) {
//                 int nd = mp[u][i].first, dis = mp[u][i].second;
//                 if (dp[nd] > w + dis) {
//                     dp[nd] =  w + dis;
//                     ver.push_back(make_pair(nd, make_pair(steps, w + dis)));
//                 } 
//             }
//         }
        
//         return (mini == INT_MAX) ? -1 : mini;
    }
};