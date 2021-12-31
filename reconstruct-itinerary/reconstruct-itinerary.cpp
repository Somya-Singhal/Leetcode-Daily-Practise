class Solution {
public:
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        unordered_map<string,multiset<string>>adj;
        stack<string>s;
        for(auto str:tickets)
        {
            string s1=str[0];
            string s2=str[1];
            adj[s1].insert({s2});
        }
        vector<string>res;
        s.push("JFK");
        while(!s.empty())
        {
            string front=s.top();
            if(adj[front].size()==0)
            {
                res.push_back(front);
                s.pop();
            }
            else
            {
                    auto it=adj[front].begin();
                    s.push(*it);
                    adj[front].erase(it);
        
            }
        }
        reverse(res.begin(),res.end());
        return res;
    }
};