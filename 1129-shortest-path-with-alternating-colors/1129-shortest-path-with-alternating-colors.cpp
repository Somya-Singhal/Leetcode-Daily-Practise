class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<int>>res(n,vector<int>(2,-1));
        vector<vector<pair<int,int>>>adj(n,vector<pair<int,int>>());
        vector<int>ans;
        for(auto x: redEdges)
        {
            adj[x[0]].push_back({x[1],0});
        }
        for(auto x: blueEdges)
        {
            adj[x[0]].push_back({x[1],1});
        }
        queue<pair<int,int>>q;
        q.push({0,0});
        q.push({0,1});
        res[0][0]=0,res[0][1]=0;
        while(!q.empty())
        {
            auto [i,c1]=q.front();
            q.pop();
            for(auto [j,c2]: adj[i])
            {
                if(res[j][c2]==-1 && c2!=c1)
                {
                    res[j][c2]=1+res[i][c1];
                    q.push({j,c2});
                }
            } 
        }
        for(auto x: res)
        {
            if(x[0]==-1 && x[1]!=-1)
                ans.push_back(x[1]);
            else if(x[0]!=-1 && x[1]==-1)
                ans.push_back(x[0]);
            else
                x[0]<x[1]?ans.push_back(x[0]):ans.push_back(x[1]);
        }
        return ans;
    }
};