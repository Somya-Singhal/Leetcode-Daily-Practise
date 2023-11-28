class Solution {
public:
    void dfs(int source,vector<vector<pair<int,int>>>& graph,vector<int>& vis,int maxTime, int &ans,int currCost,vector<int>& values){
        if(source==0){
            ans = max(ans,currCost);
        }
        if(vis[source]==0){
            currCost+=values[source];
        }
        vis[source]+=1;
        for(auto x : graph[source]){
            int edge=x.first,weight=x.second;
            if(weight<=maxTime){   
                dfs(edge,graph,vis,maxTime-weight,ans,currCost,values);
            }
        }
        vis[source]-=1;
    }
    int maximalPathQuality(vector<int>& values, vector<vector<int>>& edges, int maxTime) {
        int n=values.size();
        vector<vector<pair<int,int>>>graph(n,vector<pair<int,int>>());
        vector<int>vis(n,0);
        for(int i=0;i<edges.size();i++){
            int u=edges[i][0];
            int v=edges[i][1];
            graph[u].push_back({v,edges[i][2]});
            graph[v].push_back({u,edges[i][2]});
        }
        unordered_set<int>s;
        int ans=values[0];
        dfs(0,graph,vis,maxTime,ans,0,values);
        return ans;
    }
};