class Solution {
public:
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        vector<vector<int>>adj(n,vector<int>());
         vector<int>color(n,0);
        for(auto x:paths)
        {
            int u=x[0]-1;
            int v=x[1]-1;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        //bfs
       for(int i=0;i<n;i++)
       {
           unordered_set<int>s;
           for(auto x:adj[i])
           {
               if(color[x]!=0)
                   s.insert({color[x]});
           }
           if(s.empty())
               color[i]=1;
           else
           {
               for(int j=1;j<=4;j++)
               {
                   if(s.find(j)==s.end())
                   {
                       color[i]=j;
                       break;
                   }
               }
           }
       }
        return color;
    }
};