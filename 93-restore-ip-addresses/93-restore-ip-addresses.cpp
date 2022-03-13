class Solution {
public:
    vector<string>res;
    void mysolve(int i,int dots,string str,string &s)
    {
        // cout<<str<<" ";
        if(dots>4)
        {
             return;
        }
        if(dots==4 && i==s.length())
        {
            str.pop_back();
            res.push_back(str);
            return;
        }
        for(int j=i;j<i+3 && j<s.length();j++)
        {
            // cout<<stoi(s.substr(i,j+1-i))<<" ";
            if(stoi(s.substr(i,j+1-i))<256 && (i==j || s[i]!='0'))
            {
                 mysolve(j+1,dots+1,str+s.substr(i,j+1-i)+".",s);
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        if(s.length()>12)
            return {};
        mysolve(0,0,"",s);
        return res;
    }
};