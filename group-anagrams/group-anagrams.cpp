class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>res;
        map<map<char,int>,vector<string>>m1;
        for(auto x: strs)
        {
            vector<string>list;
            map<char,int>m2;
            for(int i=0;i<x.length();i++)
            {
                m2[x[i]]++;
            }
            auto it=m1.find(m2);
            if(it!=m1.end())
            {
               it->second.push_back(x);
            }
            else
            {
               list.push_back(x); 
               m1.insert({m2,list});
            }
        }
        for(auto x: m1)
        {
            res.push_back(x.second);
        }
        return res;
    }
};