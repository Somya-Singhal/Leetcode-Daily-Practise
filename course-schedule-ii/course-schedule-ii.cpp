class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>res;
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
                return {};
            indegree[u]++;
            adj[v].push_back(u);
        }
        for(int i=0;i<numCourses;i++)
        {
            if(!indegree[i])
            {
                res.push_back(i);
                q.push(i);
            }
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
                    {
                        res.push_back(v);
                         q.push(v);
                    }
                }
            }
            count++;
        }
        if(count==numCourses)
            return res;
        return {};
    }
};