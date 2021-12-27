class Solution {
public:
//     int maxht=INT_MIN;
//     void dfs(int i,vector<bool>& visited,vector<vector<int>>& adj,int currht)
//     {
//         visited[i]=true;
//         for(auto x:adj[i])
//         {
//             if(!visited[x])
//             {
//                 dfs(x,visited,adj,1+currht);
//             }
//         }
//         if(currht>maxht)
//             maxht=currht;
//         return;
//     }
//     vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
//         vector<int>nodes;
//         vector<vector<int>>adj(n,vector<int>());
//         for(auto x:edges)
//         {
//             int u=x[0];
//             int v=x[1];
//             adj[u].push_back(v);
//             adj[v].push_back(u);
//         }
//         int minht=INT_MAX;
//         for(int i=0;i<n;i++)
//         {
//             vector<bool>visited(n,false);
//             maxht=INT_MIN;
//             dfs(i,visited,adj,0);
            
//             if(maxht<minht)
//             {
//                 nodes.clear();
//                 nodes.push_back(i);
//                 minht=maxht;
//             }
//             else if(minht==maxht)
//             {
//                  nodes.push_back(i);
//             }
//         }
//         return nodes;
//     }
    
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>nodes;
        if(n==1)
            return nodes={0};
        vector<int>indegree(n,0);
        queue<int>q;
        vector<vector<int>>adj(n,vector<int>());
        for(auto x:edges)
        {
            int u=x[0];
            int v=x[1];
            indegree[u]++;
            indegree[v]++;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        for(int i=0;i<indegree.size();i++)
        {
            if(indegree[i]==1)
            {
                 q.push(i);
            }
        }
        int remainingnodes=n;
        while(remainingnodes>2)
        {
            int len=q.size();
            remainingnodes-=len;
            while(len--)
            {
                int top=q.front();
                q.pop();
                for(auto i:adj[top])
                {
                    indegree[i]--;
                    if(indegree[i]==1)
                    {
                        q.push(i);
                        // cout<<u<<" ";
                    }
                }
            }
        }
        while(!q.empty())
        {
            int top=q.front();
            q.pop();
            nodes.push_back(top);
        }
        return nodes;
    }
};