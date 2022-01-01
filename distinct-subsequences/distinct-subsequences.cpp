class Solution {
public:
    //recursive
    // int distinctrec(int i,int j,string s,string t)
    // {
    //     // cout<<s<<" "<<"\n";
    //     if(s==t || s.substr(0,i)==t)
    //         return 1;
    //     if(i==s.length() || j==t.length() || s.length()<t.length())
    //         return 0;
    //     if(s[i]==t[j])
    //         return distinctrec(i+1,j+1,s,t)+distinctrec(i,j,s.erase(i,1),t);
    //     return distinctrec(i,j,s.erase(i,1),t);
    // }
    // int numDistinct(string s, string t) {
    //     return distinctrec(0,0,s,t);
    // }
    
    //dp
     int numDistinct(string s, string t) {
         int n=s.length();
         int m=t.length();
         vector<long long>dp(n+1,0);
         for(int i=0;i<=n;i++)
         {
             dp[i]=1;
         }
         int temp=1,prev=0;
         for(int i=1;i<=m;i++)
         {
             for(int j=0;j<=n;j++)
             {
                 temp=dp[j];
                 if(j==0)
                     dp[j]=0;
                 else if(t[i-1]==s[j-1])
                     dp[j]=prev+dp[j-1];
                 else
                 {
                     dp[j]=dp[j-1];
                 }
                 prev=temp;
             }
         }
         return dp[n];
    }
};