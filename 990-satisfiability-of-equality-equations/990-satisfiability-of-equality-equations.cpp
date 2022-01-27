class Solution {
public:
//     bool dfs(int src,int dst,unordered_map<int,unordered_set<int>>& adj,unordered_set<int>& vis)
//     {
//         vis.insert({src});
//         for(auto x: adj[src])
//         {
//             if(x==dst)
//                 return true;
//             if(vis.find(x)==vis.end())
//             {
//                if(dfs(x,dst,adj,vis))
//                    return true;
//             }
//         }
//         return false;
//     }
//     bool equationsPossible(vector<string>& equations) {
//         int n=equations.size();
//         unordered_map<int,unordered_set<int>>adj;
//         for(int i=0;i<n;i++)
//         {
//             string str=equations[i];
//             int first=str[0]-'a';
//             int second=str[3]-'a';
//             if(str[1]=='=')
//             {
//                 adj[first].insert({second});
//                 adj[second].insert({first});
//             }
//             if(first==second && str[1]=='!')
//                 return false;
//         }
//         for(int i=0;i<n;i++)
//         {
//             string str=equations[i];
//             int first=str[0]-'a';
//             int second=str[3]-'a';
//             if(str[1]=='!')
//             {
//                 if(adj[first].find(second)!=adj[first].end())
//                     return false;
//                 unordered_set<int>vis;
//                 if(dfs(first,second,adj,vis))
//                     return false;
//             }
//             if(str[1]=='=')
//             {
//                 if(adj[first].find(second)==adj[first].end())
//                     return false;
//             }
//         }
//         return true;
//     }
    
     //union find
    int parent[26];
    int find(int x)
    {
        if(x!=parent[x])
            return parent[x]=find(parent[x]);
        return parent[x];
    }
     bool equationsPossible(vector<string>& equations) {
        int n=equations.size();
        for(int i=0;i<26;i++)
             parent[i]=i;
        for(auto x: equations)
        {
            if(x[1]=='=')
            {
                parent[find(x[0]-'a')]=parent[find(x[3]-'a')];
            }
        }
        for(auto x: equations)
        {
            if(x[1]=='!')
            {
                if(parent[find(x[0]-'a')]==parent[find(x[3]-'a')])
                    return false;
            }
        }
         return true;
    }
};