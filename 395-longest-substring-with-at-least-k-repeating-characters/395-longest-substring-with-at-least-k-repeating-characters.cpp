class Solution {
public:
    // bool isvalid(vector<int>& count,int k)
    // {
    //     int letters=0,countkletters=0;
    //     for(int i=0;i<26;i++)
    //     {
    //         if(count[i]!=0)
    //             letters++;
    //         if(count[i]>=k)
    //             countkletters++;
    //     }
    //     return letters==countkletters;
    // }
    // int longestSubstring(string s, int k) {
    //     int n=s.length();
    //     int maxlen=INT_MIN;
    //     for(int i=0;i<n;i++)
    //     {
    //         vector<int>count(26,0);
    //         for(int j=i;j<n;j++)
    //         {
    //             count[s[j]-'a']++;
    //             if(isvalid(count,k))
    //                 maxlen=max(maxlen,j-i+1);
    //         }
    //     }
    //     return maxlen==INT_MIN?0:maxlen;
    // }
    
     
     int solve(int lo,int hi,string &s,int k)
     {
         if(hi<lo)
             return 0;
         vector<int>count(26,0);
         for(int i=lo;i<hi;i++)
             count[s[i]-'a']++;
         for(int part=lo;part<hi;part++)
         {
             if(count[s[part]-'a']>=k)
                 continue;
             int nextMid=part+1;
             while(nextMid<hi && count[s[nextMid]-'a']<k)
                 nextMid++;
             return max(solve(lo,part,s,k),solve(nextMid,hi,s,k));
         }
         return (hi-lo);
     }
     int longestSubstring(string s, int k) {
        int n=s.length();
        return solve(0,n,s,k);
    }
};