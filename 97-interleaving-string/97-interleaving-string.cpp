class Solution {
public:
    //recursive
//     bool Interleaverec(int i,int j,string s1, string s2, string s3,string temp1)
//     {
//         if(temp1==s3 && i==s1.length() && j==s2.length())
//          return true;
//         bool ans=false;
//         if(i<s1.length())
//            ans|=Interleaverec(i+1,j,s1,s2,s3,temp1+s1[i]);
//         if(j<s2.length())
//             ans|=Interleaverec(i,j+1,s1,s2,s3,temp1+s2[j]);
        
//         return ans;        
//     }
//     bool isInterleave(string s1, string s2, string s3) {
//          if(s1.length()+s2.length()!=s3.length())
//              return false;
//         return Interleaverec(0,0,s1,s2,s3,"");
//     }
    
    //memoization
    // unordered_map<string,bool>memo;
    // bool Interleaverec(int p1,int p2,int p3,string s1, string s2, string s3,int n1,int n2,int n3)
    // {
    //     if(p3==n3)
    //         return (p1==n1 && p2==n2)?true:false;
    //     string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
    //     if(memo.find(key)!=memo.end())
    //         return memo[key];
    //     if(p1==n1)
    //         return memo[key]=s2[p2]==s3[p3]?Interleaverec(p1,p2+1,p3+1,s1,s2,s3,n1,n2,n3):false;
    //     if(p2==n2)
    //         return memo[key]=s1[p1]==s3[p3]?Interleaverec(p1+1,p2,p3+1,s1,s2,s3,n1,n2,n3):false;
    //     bool first=false,second=false;
    //     if(s1[p1]==s3[p3])
    //         first=Interleaverec(p1+1,p2,p3+1,s1,s2,s3,n1,n2,n3);
    //     if(s2[p2]==s3[p3])
    //         second=Interleaverec(p1,p2+1,p3+1,s1,s2,s3,n1,n2,n3);
    //     return memo[key]=first || second;
    // }
    // bool isInterleave(string s1, string s2, string s3) {
    //      int n1=s1.length();
    //      int n2=s2.length();
    //      int n3=s3.length();
    //     if(n1+n2!=n3)
    //         return false;
    //     return Interleaverec(0,0,0,s1,s2,s3,n1,n2,n3);
    // }
    
    //dp-->2D array used-->space--->O(m*n)
    //   bool isInterleave(string s1, string s2, string s3) {
    //       int n1=s1.length();
    //      int n2=s2.length();
    //      int n3=s3.length();
    //     if(n1+n2!=n3)
    //         return false;
    //       bool dp[n1+1][n2+1];
    //       for(int i=0;i<=n1;i++)
    //       {
    //           for(int j=0;j<=n2;j++)
    //           {
    //               if(i==0 && j==0)
    //                   dp[i][j]=true;
    //               else if(i==0)
    //               {
    //                   if(s2[j-1]==s3[i+j-1])
    //                       dp[i][j]=dp[i][j-1];
    //                   else
    //                       dp[i][j]=false;
    //               }
    //               else
    //               {
    //                   if(i!=0 && j!=0 && s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1])
    //                       dp[i][j]=dp[i-1][j] || dp[i][j-1];
    //                   else if(s1[i-1]==s3[i+j-1])
    //                       dp[i][j]=dp[i-1][j];
    //                   else if(j!=0 && s2[j-1]==s3[i+j-1])
    //                       dp[i][j]=dp[i][j-1];
    //                   else
    //                       dp[i][j]=false;
    //               }
    //           }
    //       }
    //       return dp[n1][n2]; 
    // }
    
    //dp-->space-->O(n)
     // bool isInterleave(string s1, string s2, string s3) {
     //     int m=s1.length();
     //     int n=s2.length();
     //     if(m+n!=s3.length())
     //         return false;
     //     bool dp[n+1];
     //     for(int i=0;i<=m;i++)
     //     {
     //         for(int j=0;j<=n;j++)
     //         {
     //             if(i==0 && j==0)
     //                 dp[j]=true;
     //             else if(i==0)
     //              {
     //                  if(s2[j-1]==s3[i+j-1])
     //                      dp[j]=dp[j-1];
     //                  else
     //                      dp[j]=false;
     //              }
     //            else
     //              {
     //                  if(i!=0 && j!=0 && s1[i-1]==s3[i+j-1] && s2[j-1]==s3[i+j-1])
     //                      dp[j]=dp[j] || dp[j-1];
     //                  else if(s1[i-1]==s3[i+j-1])
     //                     continue;
     //                  else if(j!=0 && s2[j-1]==s3[i+j-1])
     //                      dp[j]=dp[j-1];
     //                  else
     //                      dp[j]=false;
     //              }
     //         }
     //     }
     //     return dp[n];
     // }
    
      unordered_map<string,bool>m;
   bool solve(int i,int j,string a,string b,string c)
   {
       int n3=c.length(),n1=a.length(),n2=b.length();
       if(n3==0 && i==n1 && j==n2)
       return true;
       string str=to_string(i)+""+to_string(j)+""+c;
       if(m.find(str)!=m.end())
       return m[str];
       if(a[i]==c[0] && b[j]==c[0])
       return m[str]=solve(i+1,j,a,b,c.substr(1)) || solve(i,j+1,a,b,c.substr(1));
       else if(a[i]==c[0])
       return m[str]=solve(i+1,j,a,b,c.substr(1));
       else if(b[j]==c[0])
       return m[str]=solve(i,j+1,a,b,c.substr(1));
       
       return m[str]=false;
   }
    bool isInterleave(string a, string b, string c) 
    {
        //Your code here
        int n1=a.length(),n2=b.length(),n3=c.length();
        if(n1==0)
        return b==c;
        if(n2==0)
        return a==c;
        if(n3!=n1+n2)
        return false;
       
        return solve(0,0,a,b,c);
    }
    
};