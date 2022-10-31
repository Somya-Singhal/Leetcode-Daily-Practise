class Solution {
public:
    void solve(int i,string str,unordered_map<char,vector<char>>& digitToLetter,string digits,vector<string>& ans)
    {
        
        if(i==digits.length())
            ans.push_back(str);
        vector<char>temp=digitToLetter[digits[i]];
        for(int j=0;j<temp.size();j++)
        {
           
            solve(i+1,str+temp[j],digitToLetter,digits,ans);
        }
    }
    vector<string> letterCombinations(string digits) {
        unordered_map<char,vector<char>>digitToLetter;
        vector<string>ans;
        if(digits.length()==0)
            return ans;
        digitToLetter['2']={'a','b','c'};
        digitToLetter['3']={'d','e','f'};
        digitToLetter['4']={'g','h','i'};
        digitToLetter['5']={'j','k','l'};
        digitToLetter['6']={'m','n','o'};
        digitToLetter['7']={'p','q','r','s'};
        digitToLetter['8']={'t','u','v'};
        digitToLetter['9']={'w','x','y','z'};
        solve(0,"",digitToLetter,digits,ans);
        return ans;
    }
};