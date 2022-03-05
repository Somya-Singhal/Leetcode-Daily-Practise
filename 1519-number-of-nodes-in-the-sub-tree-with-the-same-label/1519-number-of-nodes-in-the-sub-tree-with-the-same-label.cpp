class Solution {
public:
    vector<int> postorder(int s,vector<vector<int>>& graph,string &labels,vector<int>& vis,vector<int>& res)
    {
        vector<int>count(26,0);
        count[labels[s]-'a']=1;
        vis[s]=1;
            for(auto &x:graph[s])
            {
                if(!vis[x])
                {
                    vector<int>cnt=postorder(x,graph,labels,vis,res);
                    for(int i=0;i<26;i++)
                    count[i]+=cnt[i];
                }
            }
        res[s]=count[labels[s]-'a'];
        return count;
    }
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int>res(n,0);
        vector<vector<int>>graph(n,vector<int>());
        vector<int>vis(n,0);
        for(auto x: edges)
        {
            graph[x[0]].push_back(x[1]);
            graph[x[1]].push_back(x[0]);
        }
        postorder(0,graph,labels,vis,res);
        return res;
    }
};