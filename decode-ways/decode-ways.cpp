class Solution {
public:
    //recursive--->O(2^n)  (Either pair up or be single)
    // int numrec(int i,string s)
    // {
    //     if(i==s.length())
    //         return 1;
    //     int ans=0;
    //     if(s[i]>'0' && s[i]<='9')
    //       ans+=numrec(i+1,s);
    //     if(i<s.length()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
    //         ans+=numrec(i+2,s);
    //     return ans;
    // }
    // int numDecodings(string s) {
    //     int n=s.length();
    //     return numrec(0,s);
    // }
    int numrec(int i,string s,vector<int>& dp)
    {
        if(i==s.length())
            return 1;
        if(dp[i]!=-1)
            return dp[i];
        int ans=0;
        if(s[i]>'0' && s[i]<='9')
          ans+=numrec(i+1,s,dp);
        if(i<s.length()-1 && (s[i]=='1' || (s[i]=='2' && s[i+1]<'7')))
            ans+=numrec(i+2,s,dp);
        return dp[i]=ans;
    }
    int numDecodings(string s) {
        int n=s.length();
        vector<int>dp(n,-1);
        return numrec(0,s,dp);
    }
};