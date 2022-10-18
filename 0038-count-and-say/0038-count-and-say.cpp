class Solution {
public:
    string solve(int n)
    {
        if(n==1)
            return "1";
        string str=solve(n-1);
        int count=1;
        string s="";
        for(int i=1;i<str.length();i++)
        {
            if(str[i]==str[i-1])
                count+=1;
            else
            {
                s+=to_string(count)+str[i-1];
                count=1;
            }
        }
        s+=to_string(count)+str[str.length()-1];
        return s;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};