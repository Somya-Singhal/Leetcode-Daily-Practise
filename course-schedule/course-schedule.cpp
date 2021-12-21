class Solution {
public:
    //find all nodes can be visited or not
    bool dfs(int i,vector<bool>& visited,vector<bool>& rectst,vector<vector<int>>& adj)
    {
        visited[i]=true;
        rectst[i]=true;
        for(auto x:adj[i])
        {
            if(!visited[x] && dfs(x,visited,rectst,adj))
                return true;
            else if(rectst[x]==true)
                return true;
        }
        rectst[i]=false;
        return false;
    }
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        if(prerequisites.size()==0)
            return true;
        // vector<int>outdegree(numCourses,0);
        vector<vector<int>>adj(numCourses,vector<int>());
        int max_outdegree=0;
        for(auto x:prerequisites)
        {
            int u=x[0];
            int v=x[1];
            if(u==v)
                return false;
            // outdegree[u]++;
            // if(outdegree[u]>outdegree[max_outdegree])
            //   max_outdegree=u;
            adj[u].push_back(v);
        }
        for(int i=0;i<numCourses;i++)
        {
            vector<bool>visited(numCourses,false);
            vector<bool>rectst(numCourses,false);
            if(dfs(i,visited,rectst,adj)==true)
              return false;
        }
        return true;
    }
};