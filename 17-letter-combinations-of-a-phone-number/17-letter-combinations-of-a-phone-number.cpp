class Solution {
public:
    // void solve(int idx,string s,string &digits,vector<string>& res,vector<string>& mp)
    // {
    //     if(idx==digits.size())
    //     {
    //         res.push_back(s);
    //         return;
    //     }
    //     for(auto x:mp[digits[idx]-'2'])
    //         solve(idx+1,s+x,digits,res,mp);
    //     return;
    // }
    
    //  void solve(int idx,string &s,string &digits,vector<string>& res,vector<string>& mp)
    // {
    //     if(idx==digits.size())
    //     {
    //         res.push_back(s);
    //         return;
    //     }
    //     for(auto x:mp[digits[idx]-'2'])
    //     {
    //          s+=x;
    //          solve(idx+1,s,digits,res,mp);
    //          s.pop_back();
    //     }
    //     return;
    // }
    // vector<string> letterCombinations(string digits) {
    //    int n=digits.length();
    //     vector<string>mp={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
    //     vector<string>res;
    //     if(digits=="")
    //         return res;
    //     string str="";
    //    solve(0,str,digits,res,mp);
    //   return res;  
    // }
    
    vector<string> letterCombinations(string digits) {
       int n=digits.length();
        vector<string>mp={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        if(digits=="")
            return res;
        queue<string>q;
        for(auto c:mp[digits[0]-'2'])
        {
            string s="";
            s+=c;
            q.push(s);
        }
        for(int i=1;i<n;i++)
        {
            int len=q.size();
             while(len>0)
            {
                string s=q.front();
                q.pop();
                 len--;
                for(auto c:mp[digits[i]-'2'])
                q.push(s+c);
            }
        }
        while(!q.empty())
        {
            string s=q.front();
            res.push_back(s);
            q.pop();
        }
      return res;  
    }
};