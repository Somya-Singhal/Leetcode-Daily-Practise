class Solution {
public:
    //bfs
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        vector<int>count(n,0);
        int res;
        for(auto x: edges)
        {
            int u=x[0],v=x[1];
            adj[u].push_back(make_pair(v,x[2]));
            adj[v].push_back(make_pair(u,x[2]));
        }
        for(int i=0;i<n;i++)
        {
            priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
            vector<int>dist(n,INT_MAX);
            pq.push(make_pair(0,i));
            dist[i]=0;
            while(!pq.empty())
            {
                int wt=pq.top().first;
                int u=pq.top().second;
                pq.pop();
                for(auto x: adj[u])
                {
                    if(wt+x.second<dist[x.first])
                    {
                        pq.push(make_pair(wt+x.second,x.first));
                        dist[x.first]=wt+x.second;
                    }
                }
            }
            int ans=0;
            for(int j=0;j<n;j++)
            {
                if(j!=i && dist[j]<=distanceThreshold)
                    ans++;
            }
            count[i]=ans;
        }
        int finalcnt=INT_MAX;
        for(int i=0;i<n;i++)
        {
            cout<<count[i]<<" ";
            if(count[i]<=finalcnt)
            {
                res=i; 
                finalcnt=count[i];
            }
        }
        cout<<endl;
        return res;
    }
};