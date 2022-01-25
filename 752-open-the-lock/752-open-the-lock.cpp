class Solution {
public:
    vector<string> children(string str)
    {
        vector<string>v;
        for(int i=0;i<str.length();i++)
        {
           string s1=str.substr(0,i)+(str[i]=='9'?"0":to_string(str[i]-'0'+1))+str.substr(i+1);
           v.push_back(s1);
           string s2=str.substr(0,i)+(str[i]=='0'?"9":to_string(str[i]-'0'-1))+str.substr(i+1);
           v.push_back(s2);
        }
        return v;
    }
    int openLock(vector<string>& deadends, string target) {
        queue<pair<string,int>>q;
        unordered_set<string>vis;
        int n=deadends.size();
        for(int i=0;i<n;i++)
        {
            if(deadends[i]=="0000")
                return -1;
           vis.insert({deadends[i]});
        }
        q.push(make_pair("0000",0));
        vis.insert({"0000"});
        while(!q.empty())
        {
            string str=q.front().first;
            int moves=q.front().second;
            q.pop();
            if(str==target)
                return moves;
            for(auto i:children(str))
            {
                if(vis.find(i)==vis.end())
                {
                    q.push(make_pair(i,moves+1));
                    vis.insert({i});
                }
            }
        }
        return -1;
    }
};