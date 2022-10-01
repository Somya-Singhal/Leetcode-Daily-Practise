class Solution {
public:
    // int solve(int s,string str,vector<int>& dp)
    // {
    //     int n=str.length();
    //     if(s==n)
    //         return 1;
    //     if(str[s]=='0')
    //         return 0;
    //     if(dp[s]!=0)
    //         return dp[s];
    //     int count=0;
    //     if(str[s]>'0' && str[s]<='9')
    //         count+=solve(s+1,str,dp);
    //     if(s<n-1 && (str[s]=='1' || (str[s]=='2' && str[s+1]<'7')))
    //         count+=solve(s+2,str,dp);
    
    //*******this code worked but giving TLE  ***** //
    //     // for(int k=s;k<n;k++)
    //     // {
    //     //     if(k-s>1)
    //     //         break;
    //     //     stringstream ss;
    //     //     string sub=str.substr(s,k-s+1);
    //     //     int num;
    //     //     ss<<sub;
    //     //     ss>>num;
    //     //     if(num>0 && num<27)
    //     //         count+=solve(k+1,str,dp);
    //     // }
    //*******          ***********//
    //     dp[s]=count;
    //     return dp[s];
    // }
    // int numDecodings(string s) {
    //     int n=s.length();
    //     vector<int>dp(n+1,0);
    //    return solve(0,s,dp);
    // }
    
     int numDecodings(string str) {
        int n=str.length();
        vector<int>dp(n+1,0);
        dp[n]=1;
        for(int s=n-1;s>=0;s--)
        {
            if(str[s]=='0')
              continue;
            int count=0;
            if(str[s]>'0' && str[s]<='9')
                count+=dp[s+1];
            if(s<n-1 && (str[s]=='1' || (str[s]=='2' && str[s+1]<'7')))
                count+=dp[s+2];
            dp[s]=count;    
        }
       return dp[0];
    }
};