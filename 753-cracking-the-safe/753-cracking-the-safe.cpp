class Solution {
public:
    //dfs
    bool dfs(string &ans,unordered_set<string>& s,int total,int n,int k)
    {
        if(s.size()==total)
            return true;
        string str=ans.substr(ans.length()-n+1);
        for(char ch='0';ch<'0'+k;ch++)
        {
            string temp=str+ch;
            if(s.find(temp)==s.end())
            {
                s.insert({temp});
                ans+=ch;
                if(dfs(ans,s,total,n,k))
                {
                    return true;
                }
                s.erase(temp);
                ans.pop_back();
            }
        }
        return false;
    }
    string crackSafe(int n, int k) {
       int total=pow(k,n);
        string ans(n,'0');
        unordered_set<string>s;
        s.insert({ans});
        dfs(ans,s,total,n,k);
        return ans;
    }
};