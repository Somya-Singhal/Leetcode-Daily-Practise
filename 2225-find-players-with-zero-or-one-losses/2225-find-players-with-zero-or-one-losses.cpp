class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n=matches.size();
        vector<vector<int>>res;
        vector<int>win,one_loose;
        map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[matches[i][1]]++;
            if(m.find(matches[i][0])==m.end())
                m.insert({matches[i][0],0});
        }
        unordered_set<int>vis;
        for(int i=0;i<n;i++)
        {
            if(vis.find(matches[i][0])==vis.end())
            {
                if(m[matches[i][0]]==0)
                {
                    win.push_back(matches[i][0]);
                    vis.insert(matches[i][0]);
                }
                else if(m[matches[i][0]]==1)
                {
                    one_loose.push_back(matches[i][0]);
                    vis.insert(matches[i][0]);
                }
                
            }
            if(vis.find(matches[i][1])==vis.end())
            {
                if(m[matches[i][1]]==0)
                {
                    win.push_back(matches[i][1]);
                    vis.insert(matches[i][1]);
                }
            
                if(m[matches[i][1]]==1)
                {
                    one_loose.push_back(matches[i][1]);
                    vis.insert(matches[i][1]);
                }
            }
            
            
        }
        sort(win.begin(),win.end());
        sort(one_loose.begin(),one_loose.end());
        res.push_back(win);
        res.push_back(one_loose);
        return res;
    }
};