class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>res;
        int n=graph.size();
        vector<bool>safe(n,false);
        vector<vector<int>>rgraph(n,vector<int>());
        queue<int>q;
        for(int i=0;i<n;i++)
        {
            if(graph[i].size()==0)
                q.push(i);
            for(auto x:graph[i])
                rgraph[x].push_back(i);
        }
        while(!q.empty())
        {
            int j=q.front();
            safe[j]=true;
            q.pop();
            for(auto x:rgraph[j])
            {
                for(int i=0;i<graph[x].size();i++)
                {
                    if(graph[x][i]==j)
                    {
                        graph[x].erase(graph[x].begin()+i);
                        break;
                    }
                }
                if(graph[x].empty())
                    q.push(x);
            }
        }
        for(int i=0;i<n;i++)
        {
            if(safe[i])
                res.push_back(i);
        }
        return res;
    }
};