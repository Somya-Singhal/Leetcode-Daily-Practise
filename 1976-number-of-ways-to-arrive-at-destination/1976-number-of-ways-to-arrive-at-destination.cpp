 #define ll long long
 #define pll pair<ll,ll>
class Solution {
public:
    //flyod warshall
    int mod=1e9+7;
    int countPaths(int n, vector<vector<int>>& roads) {
        vector<vector<pll>>dp(n);
        for(auto &x: roads)
        {
            dp[x[0]].push_back({x[1],x[2]});
            dp[x[1]].push_back({x[0],x[2]});
        }
       vector<ll>dist(n,LONG_MAX);
       vector<ll>ways(n,0);
       dist[0]=0;
       ways[0]=1;
       priority_queue<pll,vector<pll>,greater<>>pq;
        pq.push({0,0});
        while(!pq.empty())
        {
           auto[wt,u]=pq.top();
           pq.pop();
           if(wt>dist[u])
                continue;
           for(auto x:dp[u])
           {
               ll v=x.first;
               ll wtv=x.second;
               if(dist[v]>wt+wtv)
               {
                  dist[v]=wt+wtv;
                  ways[v]=ways[u];
                  pq.push(make_pair(dist[v],v));
               }
               else if(dist[v]==wt+wtv)
               {
                   ways[v]=(ways[u]+ways[v])%mod;
               }
           }
        }
        return ways[n-1];
    }
};