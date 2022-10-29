class Solution {
public:
    bool matchReplacement(string s, string sub, vector<vector<char>>& mappings) {
        int slen=s.length(),sublen=sub.length();
        unordered_map<char,unordered_set<char>>mp;
        for(int i=0;i<mappings.size();i++)
        {
            mp[mappings[i][0]].insert(mappings[i][1]);
        }
        for(int i=0,j=0;i+sublen<=slen;i++)
        {
            for(j=0;j<sublen;j++)
            {
                if(s[i+j]!=sub[j] && mp[sub[j]].count(s[i+j])==0)
                    break;
                
            }
            if(j==sublen)
                return true;
        }
        return false;
    }
};