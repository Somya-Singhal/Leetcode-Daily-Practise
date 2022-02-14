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
    
     
     // int solve(int lo,int hi,string &s,int k)
     // {
     //     if(hi<lo)
     //         return 0;
     //     vector<int>count(26,0);
     //     for(int i=lo;i<hi;i++)
     //         count[s[i]-'a']++;
     //     for(int part=lo;part<hi;part++)
     //     {
     //         if(count[s[part]-'a']>=k)
     //             continue;
     //         int nextMid=part+1;
     //         while(nextMid<hi && count[s[nextMid]-'a']<k)
     //             nextMid++;
     //         return max(solve(lo,part,s,k),solve(nextMid,hi,s,k));
     //     }
     //     return (hi-lo);
     // }
    //  int longestSubstring(string s, int k) {
    //     int n=s.length();
    //     return solve(0,n,s,k);
    // }
    
     int getTotalUnique(string &s)
     {
         int n=s.length();
         int count=0;
         vector<bool>mp(26,false);
         for(int i=0;i<n;i++)
         {
             if(mp[s[i]-'a']==false)
                 count++;
             mp[s[i]-'a']=true;
         }
         return count;
     }
     int longestSubstring(string s, int k) {
        int n=s.length();
        int count[26];
         int maxlen=0;
         int totalUnique=getTotalUnique(s);
         for(int currUnique=1;currUnique<=totalUnique;currUnique++)
         {
             memset(count,0,sizeof(count));
             int start=0,end=0,idx=0,unique=0,countKele=0;
             while(end<n)
             {
                 if(unique<=currUnique)
                 {
                     idx=s[end]-'a';
                     if(count[idx]==0)
                         unique++;
                     count[idx]++;
                     if(count[idx]==k)
                         countKele++;
                     end++;
                 }
                 else
                 {
                    idx=s[start]-'a';
                    if(count[idx]==k)
                        countKele--;
                     count[idx]--;
                     if(count[idx]==0)
                         unique--;
                     start++;
                 }
                 if(unique==currUnique && unique==countKele)
                   maxlen=max(maxlen,end-start);  
             }
         }
         return maxlen;
    }
};