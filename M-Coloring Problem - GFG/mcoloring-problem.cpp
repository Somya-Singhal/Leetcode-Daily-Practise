// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
// Function to determine if graph can be coloured with at most M colours such
// that no two adjacent vertices of graph are coloured with same colour.
// bool solve(vector<int>& color,vector<bool>& vis,vector<vector<int>>& adj,int m,int n)
// {
//     int maxcolor=1;
//     for(int j=0;j<n;j++)
//     {
//         if(vis[j])
//         continue;
//         vis[j]=true;
//         queue<int>q;
//         q.push(j);
//         while(!q.empty())
//         {
//             int t=q.front();
//             q.pop();
//             for(auto x: adj[t])
//             {
//                 if(color[t]==color[x])
//                 color[x]+=1;
//                 maxcolor=max(maxcolor,max(color[x],color[t]));
//                 if(maxcolor>m)
//                 return 0;
//                 if(!vis[x])
//                 {
//                     vis[x]=true;
//                     q.push(x);
//                 }
//             }
            
//         }
//     }
//     return 1;
// }
bool valid(int i,int c,vector<int>& color,bool graph[101][101],int n)
{
    for(int j=0;j<n;j++)
    {
        if(graph[i][j] && color[j]==c)
        return false;
    }
    return true;
}
bool solve(int id,vector<int>& color,bool graph[101][101], int m, int n)
{
    if(id==n)
    return true;
    for(int i=1;i<=m;i++)
    {
        
        if(valid(id,i,color,graph,n))
        {
            color[id]=i;
            if(solve(id+1,color,graph,m,n)==true)
            return true;
            color[id]=0;
        }
    }
    return false;
}

bool graphColoring(bool graph[101][101], int m, int n) {
    // your code here
    vector<int>color(n,0);
    // vector<bool>vis(n,false);
    // vector<vector<int>>adj(n,vector<int>(n,0));
    // for(int i=0;i<n;i++)
    // {
    //     for(int j=0;j<n;j++)
    //     {
    //         if(graph[i][j])
    //         {
    //             adj[i].push_back(j);
    //             adj[j].push_back(i);
    //         }
    //     }
    // }
    return solve(0,color,graph,m,n);
}

// { Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m, e;
        cin >> n >> m >> e;
        int i;
        bool graph[101][101];
        for (i = 0; i < n; i++) {
            memset(graph[i], 0, sizeof(graph[i]));
        }
        for (i = 0; i < e; i++) {
            int a, b;
            cin >> a >> b;
            graph[a - 1][b - 1] = 1;
            graph[b - 1][a - 1] = 1;
        }
        cout << graphColoring(graph, m, n) << endl;
    }
    return 0;
}
  // } Driver Code Ends