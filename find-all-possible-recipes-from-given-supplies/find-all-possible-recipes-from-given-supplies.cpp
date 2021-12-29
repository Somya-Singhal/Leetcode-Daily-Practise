class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>indegree;
        unordered_map<string,vector<string>>adj;
        vector<string>res;
        int n=recipes.size();
        int m=supplies.size();
        for(int i=0;i<n;i++)
        {
            for(auto x:ingredients[i])
            {
               adj[x].push_back({recipes[i]});
               indegree[recipes[i]]++;
            }
        }
        queue<string>q;
        for(int i=0;i<m;i++)
        {
            q.push(supplies[i]);
        }
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            for(auto x:adj[s])
            {
                indegree[x]--;
                if(indegree[x]==0)
                {
                    q.push(x);
                    res.push_back(x);
                }
            }
        }
         return res;
        }
};