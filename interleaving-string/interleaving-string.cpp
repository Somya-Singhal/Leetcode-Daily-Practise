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
    unordered_map<string,bool>memo;
    bool Interleaverec(int p1,int p2,int p3,string s1, string s2, string s3,int n1,int n2,int n3)
    {
        if(p3==n3)
            return (p1==n1 && p2==n2)?true:false;
        string key=to_string(p1)+"*"+to_string(p2)+"*"+to_string(p3);
        if(memo.find(key)!=memo.end())
            return memo[key];
        if(p1==n1)
            return memo[key]=s2[p2]==s3[p3]?Interleaverec(p1,p2+1,p3+1,s1,s2,s3,n1,n2,n3):false;
        if(p2==n2)
            return memo[key]=s1[p1]==s3[p3]?Interleaverec(p1+1,p2,p3+1,s1,s2,s3,n1,n2,n3):false;
        bool first=false,second=false;
        if(s1[p1]==s3[p3])
            first=Interleaverec(p1+1,p2,p3+1,s1,s2,s3,n1,n2,n3);
        if(s2[p2]==s3[p3])
            second=Interleaverec(p1,p2+1,p3+1,s1,s2,s3,n1,n2,n3);
        return memo[key]=first || second;
    }
    bool isInterleave(string s1, string s2, string s3) {
         int n1=s1.length();
         int n2=s2.length();
         int n3=s3.length();
        if(n1+n2!=n3)
            return false;
        return Interleaverec(0,0,0,s1,s2,s3,n1,n2,n3);
    }
};