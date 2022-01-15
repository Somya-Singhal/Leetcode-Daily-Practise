class Solution {
public:
    //no two adjacent vertices should have same color
    //dfs
    // bool dfs(long long int i,long long int curr,vector<vector<long long int>>& adj,vector<long long int>& color)
    // {
    //     color[i]=curr;
    //     for(auto x:adj[i])
    //     {
    //         if(color[x]!=0 && color[x]==curr)
    //         return false;
    //         if(color[x]==0 && !dfs(x,-curr,adj,color))
    //             return false;
    //     }
    //     return true;
    // }
    // bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
    //     vector<long long int>color(n,0);
    //     vector<vector<long long int>>adj(n,vector<long long int>());
    //     for(auto x: dislikes)
    //     {
    //         int u=x[0]-1;
    //         int v=x[1]-1;
    //         adj[u].push_back(v);
    //     }
    //     for(long long int i=0;i<n;i++)
    //     {
    //         if(color[i]==0 && !dfs(i,1,adj,color))
    //             return false;
    //     }
    //     return true;
    // }
    
    //bfs
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>color(n+1,0);
        vector<vector<int>>adj(n+1);
        for(auto &x: dislikes)
        {
            int u=x[0];
            int v=x[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=1;i<=n;i++)
        {
            if(color[i]==0)
            {
                queue<int>q;
                color[i]=1;
                q.push(i);
                while(!q.empty())
                {
                    int u=q.front();
                    q.pop();
                    for(auto &x: adj[u])
                    {
                        if(color[x]!=0)
                        {
                            if(color[x]!=-color[u])
                                return false;
                        }
                        else
                        {
                            color[x]=-color[u];
                             q.push(x);
                        }
                    }
                }
            } 
        }
        return true;
    }
};