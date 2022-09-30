class Solution {
public:
    static bool compare(const pair<int,int>&pt1,const pair<int,int>&pt2)
    {
        if(pt1.first==pt2.first)
            return pt1.second<pt2.second;
        return pt1.first<pt2.first;
    }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>>ans;
        multiset<int>s;
        vector<pair<int,int>>pt;
        int n=buildings.size();
        for(int i=0;i<n;i++)
        {
             pt.push_back({buildings[i][0],-buildings[i][2]});
             pt.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(pt.begin(),pt.end(),compare);
        s.insert(0);
        for(int i=0;i<pt.size();i++)
        {
            int x=pt[i].first;
            int ht=pt[i].second;
            int curr=*s.rbegin();
            if(ht<0)
                s.insert(-ht);
            else
              s.erase(s.find(ht));
               
            if(*s.rbegin()!=curr)
            {
                ans.push_back({x,*s.rbegin()});
            }
        }
        return ans;
    }
};