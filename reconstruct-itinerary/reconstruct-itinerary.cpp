class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
       //     vector<string> findItinerary(vector<vector<string>>& tickets) {
//         unordered_map<string,multiset<string>>adj;
//         stack<string>s;
//         for(auto str:tickets)
//         {
//             string s1=str[0];
//             string s2=str[1];
//             adj[s1].insert({s2});
//         }
//         vector<string>res;
//         s.push("JFK");
//         while(!s.empty())
//         {
//             string front=s.top();
//             if(adj[front].size()==0)
//             {
//                 res.push_back(front);
//                 s.pop();
//             }
//             else
//             {
//                     auto it=adj[front].begin();
//                     s.push(*it);
//                     adj[front].erase(it);
        
//             }
//         }
//         reverse(res.begin(),res.end());
//         return res;
//     }
     void dfs(string s,unordered_map<string,multiset<string>>& adj,vector<string>& res)
     {
         while(adj[s].size())
         {
                 auto it=adj[s].begin();
                 string newst=*it;
                 adj[s].erase(it);
                 dfs(newst,adj,res);
         }
        res.push_back(s);
     }
     vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        for(auto str:tickets)
        {
            string s1=str[0];
            string s2=str[1];
            adj[s1].insert({s2});
        }
        vector<string>res;
        dfs("JFK",adj,res);
        reverse(res.begin(),res.end());
        return res;
    }
};
