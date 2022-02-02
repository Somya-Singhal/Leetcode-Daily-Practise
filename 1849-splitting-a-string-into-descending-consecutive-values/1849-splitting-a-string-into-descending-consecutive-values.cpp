class Solution {
public:
    //backtracing
    //time->O(n^2)
    long long MX=1e10;
    bool solve(int idx,long long prev,string s)
    {
        if(idx==s.length())  
            return true;
        long long val=0;
        for(int i=idx;i<s.length();i++)
        {
            val=val*10L+s[i]-'0';
            // cout<<val<<endl;
            if(val>=MX)
                return false;
            if(val+1==prev && solve(i+1,val,s))
                return true;
        }
        return false;
    }
    bool splitString(string s) {
        int n=s.length();
        if(n<=1)
            return false;
        long long val=0;
        for(int i=0;i<n-1;i++)
        {
            val=val*10L+s[i]-'0';
            // cout<<val<<endl;
            if(val>=MX)
                return false;
            if(solve(i+1,val,s))
                return true;
        }
        return false;
    }
};