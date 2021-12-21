class Solution {
public:
   //detect cycle in a directed graph
    
    //dfs approach
    // bool dfs(int i,vector<bool>& visited,vector<bool>& rectst,vector<vector<int>>& adj)
    // {
    //     visited[i]=true;
    //     rectst[i]=true;
    //     for(auto x:adj[i])
    //     {
    //         if(!visited[x] && dfs(x,visited,rectst,adj))
    //             return true;
    //         else if(rectst[x]==true)
    //             return true;
    //     }
    //     rectst[i]=false;
    //     return false;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     if(prerequisites.size()==0)
    //         return true;
    //     vector<bool>visited(numCourses,false);
    //     vector<bool>rectst(numCourses,false);
    //     vector<vector<int>>adj(numCourses,vector<int>());
    //     int max_outdegree=0;
    //     for(auto x:prerequisites)
    //     {
    //         int u=x[0];
    //         int v=x[1];
    //         if(u==v)
    //             return false;
    //         adj[u].push_back(v);
    //     }
    //     for(int i=0;i<numCourses;i++)
    //     {
    //         if(!visited[i] && dfs(i,visited,rectst,adj)==true)
    //           return false;
    //     }
    //     return true;
    // }
    
    //kahn's algorithm used
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)
            return true;
        vector<bool>visited(numCourses,false);
        vector<int>indegree(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>());
        queue<int>q;
        int count=0;
        for(auto x:prerequisites)
        {
            int u=x[0];
            int v=x[1];
            if(u==v)
                return false;
            indegree[v]++;
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!indegree[i])
                q.push(i);
        }
        while(!q.empty())
        {
            int u=q.front();
            q.pop();
            for(auto v:adj[u])
            {
                if(!visited[v])
                {
                    indegree[v]--;
                    if(!indegree[v])
                        q.push(v);
                }
            }
            count++;
        }
        return count==numCourses;
    }
};
