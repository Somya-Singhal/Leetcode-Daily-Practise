class Solution {
public:
    void solve(int idx,string s,string digits,vector<string>& res,vector<string>& mp)
    {
        if(idx==digits.size())
        {
            res.push_back(s);
            return;
        }
        for(auto x:mp[digits[idx]-'2'])
            solve(idx+1,s+x,digits,res,mp);
        return;
    }
    vector<string> letterCombinations(string digits) {
       int n=digits.length();
        vector<string>mp={"abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string>res;
        if(digits=="")
            return res;
       solve(0,"",digits,res,mp);
      return res;  
    }
};