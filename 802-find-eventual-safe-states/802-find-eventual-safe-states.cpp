class Solution {
public:
    //time->O(V+E)
    //space-->O(V)
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<int>res;
    //     int n=graph.size();
    //     vector<bool>safe(n,false);
    //     vector<vector<int>>rgraph(n,vector<int>());
    //     queue<int>q;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(graph[i].size()==0)
    //             q.push(i);
    //         for(auto x:graph[i])
    //             rgraph[x].push_back(i);
    //     }
    //     while(!q.empty())
    //     {
    //         int j=q.front();
    //         safe[j]=true;
    //         q.pop();
    //         for(auto x:rgraph[j])
    //         {
    //             for(int i=0;i<graph[x].size();i++)
    //             {
    //                 if(graph[x][i]==j)
    //                 {
    //                     graph[x].erase(graph[x].begin()+i);
    //                     break;
    //                 }
    //             }
    //             if(graph[x].empty())
    //                 q.push(x);
    //         }
    //     }
    //     for(int i=0;i<n;i++)
    //     {
    //         if(safe[i])
    //             res.push_back(i);
    //     }
    //     return res;
    // }
    
    //dfs
    // bool dfs(int src,vector<vector<int>>& graph,vector<bool>& rect,vector<bool>& safe)
    // {
    //     safe[src]=true;
    //     rect[src]=true;
    //     for(auto x:graph[src])
    //     {
    //           if(!safe[x] && dfs(x,graph,rect,safe))
    //                 return true;
    //           else if(rect[x]==true)
    //                 return true;
    //     }
    //     rect[src]=false;
    //     return false;
    // }
    // vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
    //     vector<int>res;
    //     int n=graph.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         vector<bool>safe(n,false);
    //         vector<bool>rect(n,false);
    //         if(dfs(i,graph,rect,safe)==false)
    //             res.push_back(i);       
    //     }
    //     return res;
    // }
    
    //dfs->2nd approach
    bool dfs(int src,vector<vector<int>>& graph,vector<int>& color)
    {
        if(color[src]>0)
            return color[src]==2;
        color[src]=1;
        for(auto x:graph[src])
        {
            if(color[x]==2)
                continue;
            else if(color[x]==1 || !dfs(x,graph,color))
                    return false;
        }
        color[src]=2;
        return true;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        int n=graph.size();
        vector<int>color(n,0);
        for(int i=0;i<n;i++)
        {
            if(dfs(i,graph,color))
                res.push_back(i);       
        }
        return res;
    }
};