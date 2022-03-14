class Solution {
public:
    void dijsktra(vector<vector<pair<int,int>>>& adj,vector<long long>& dist, int src)
    {
        priority_queue<pair<long long,int>,vector<pair<long long,int>>,greater<pair<long long,int>>>pq;
        dist[src]=0;
        pq.push({0,src});
        while(!pq.empty())
        {
            long long wt=pq.top().first;
            int node=pq.top().second;
            pq.pop();
            if(dist[node]!=wt)
                continue;
            for(auto x: adj[node])
            {
                if(dist[x.first]>x.second+wt)
                {
                    dist[x.first]=x.second+wt;
                    pq.push({dist[x.first],x.first});
                }
            }
        }
    }
    long long minimumWeight(int n, vector<vector<int>>& edges, int src1, int src2, int dest) {
        long long max_val=1e10;
        vector<vector<pair<int,int>>>adj(n),radj(n);
        for(auto x: edges)
        {
            adj[x[0]].push_back(make_pair(x[1],x[2]));
            radj[x[1]].push_back(make_pair(x[0],x[2]));
        }
        vector<long long>dist1(n,max_val),dist2(n,max_val),dist3(n,max_val);
        dijsktra(adj,dist1,src1);
        dijsktra(adj,dist2,src2);
        dijsktra(radj,dist3,dest);
        long long ans=LONG_LONG_MAX;
        if(dist3[src1]==max_val || dist3[src2]==max_val)
            return -1;
        for(int i=0;i<n;i++)
            ans=min(ans,dist1[i]+dist2[i]+dist3[i]);
         return ans;
    }
};