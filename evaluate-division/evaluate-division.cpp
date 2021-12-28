class Solution {
public:
    void dfs(string i,string j,unordered_map<string,vector<pair<string,double>>>& adj,unordered_set<string>& st, double &ans,double temp)
    {
        st.insert({i});
        for(auto x:adj[i])
        {
            if(i==j)
          {
              ans=temp;
              return;
          }
            string s=x.first;
            double wt=x.second;
            if(st.find(s)==st.end())
            {
                dfs(s,j,adj,st,ans,wt*temp);
            }
        }
        return;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>adj;
        vector<double>res;
        int j=0;
        for(auto x: equations)
        {
            string s1=x[0];
            string s2=x[1];
            double wt=values[j++];
            // if(adj.find(x[0])!=adj.end())
            // adj[x[0]].push_back(make_pair(x[1],wt));
            // else
            // adj.insert({x[0],make_pair(x[1],wt)});
            // if(adj.find(x[1])!=adj.end())
            // adj[x[1]].push_back(make_pair(x[0],1/wt));
            // else
            //  adj.insert({x[1],make_pair(x[0],1/wt)});  
            adj[x[0]].push_back(make_pair(x[1],wt));
            adj[x[1]].push_back(make_pair(x[0],1/wt));
        }
        for(auto x:queries)
        {
            unordered_set<string>st;
             double ans=-1.0;
            dfs(x[0],x[1],adj,st,ans,1);
            res.push_back(ans);
        }
        return res;
    }
};