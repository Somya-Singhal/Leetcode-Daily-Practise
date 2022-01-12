class Solution {
public:
//     int find(int x,vector<int>& parent)
//     {
//         if(parent[x]==x)
//             return x;
//         return parent[x]=find(parent[x],parent);
//     }
//     bool myunion(int u,int v,vector<int>& parent,vector<int>& rank)
//     {
//         int x=find(u,parent);
//         int y=find(v,parent);
//         if(x!=y)
//         {
//             if(rank[u]>rank[v])
//                 parent[v]=u;
//             else if(rank[v]>rank[u])
//                 parent[u]=v;
//             else
//             {
//                 parent[u]=v;
//                 rank[v]++;
//             }
//             return true;
//         }
//         else
//             return false;
//     }
//     vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
//         int n=edges.size();
//         vector<int>indegree(n+1,0);
//         vector<int>parent(n+1);
//         vector<int>rank(n+1);
//         int edgeremoved=-1,makecycle=-1;
//         for(int i=0;i<n;i++)
//         {
//             int u=edges[i][0];
//             int v=edges[i][1];
//             if(indegree[v]!=0)
//             {
//                 edgeremoved=i;
//                 break;
//             }
//             else
//             {

//                 indegree[v]=u;
//             }
//         }
//         for(int i=1;i<=n;i++)
//         {
//             parent[i]=i;
//             rank[i]=1;
//         }
//         for(int i=0;i<n;i++)
//         {
//             if(i==edgeremoved)
//                 continue;
//             else
//             {
//                 int u=edges[i][0];
//                 int v=edges[i][1];
//                 if(!myunion(u,v,parent,rank))
//                 {
//                     makecycle=i;
//                     break;
//                 }
//             }
//         }
//         if(edgeremoved==-1)
//             return edges[makecycle];
//         else if(makecycle!=-1)
//         {
//             vector<int>res;
//             int u=edges[edgeremoved][1];
//             int v=parent[v];
//             res.push_back(u);
//             res.push_back(v);
//             return res;
//         }
//         return edges[edgeremoved];
//     }
// };
    
    
    vector<int> findRedundantDirectedConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int> parent(n+1, 0), candA, candB;
        // step 1, check whether there is a node with two parents
        for (auto &edge:edges) {
            if (parent[edge[1]] == 0)
                parent[edge[1]] = edge[0]; 
            else {
                candA = {parent[edge[1]], edge[1]};
                candB = edge;
                edge[1] = 0;
            }
        } 
        // step 2, union find
        for (int i = 1; i <= n; i++) parent[i] = i;
        for (auto &edge:edges) {
            if (edge[1] == 0) continue;
            int u = edge[0], v = edge[1], pu = root(parent, u);
            // Now every node only has 1 parent, so root of v is implicitly v
            if (pu == v) {
                if (candA.empty()) return edge;
                return candA;
            }
            parent[v] = pu;
        }
        return candB;
    }
private:
    int root(vector<int>& parent, int k) {
        if (parent[k] != k) 
            parent[k] = root(parent, parent[k]);
        return parent[k];
    }
};