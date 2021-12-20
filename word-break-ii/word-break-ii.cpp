class Solution {
public:
    void wordrec(int i,const string &s,string str,vector<string>& res,unordered_set<string>st)
    {
        // cout<<str<<" ";
        if(i==s.length())
        {
            res.push_back(str);
            return;
        }
        str+=" ";
        for(int k=i;k<s.length();k++)
        {
            if(st.find(s.substr(i,k-i+1))!=st.end())
            {
                wordrec(k+1,s,str+s.substr(i,k-i+1),res,st);
            }
        }
        return;
    }
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        vector<string>res;
        unordered_set<string>st;
        for(int i=0;i<wordDict.size();i++)
        {
            st.insert({wordDict[i]});
        }
        for(int i=0;i<s.length();i++)
        {
            if(st.find(s.substr(0,i+1))!=st.end())
                wordrec(i+1,s,s.substr(0,i+1),res,st);
        }
        return res;
    }
};