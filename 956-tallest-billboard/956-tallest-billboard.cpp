class Solution {
public:
    // int solve(int i,int s1,int s2,int target,vector<vector<int>>& m,vector<int>& rods)
    // {
    //     if(s1>target || s2>target)
    //         return -1;
    //     if(i>=rods.size())
    //         return s1==s2?s1:-1;
    //     if(m[i][abs(s1-s2)]==-2)
    //     {
    //        m[i][abs(s1-s2)]=max(-1,max({solve(i+1,s1,s2,target,m,rods),solve(i+1,s1+rods[i],s2,target,m,rods),solve(i+1,s1,s2+rods[i],target,m,rods)})-max(s1,s2)); 
    //     }
    //     return m[i][abs(s1-s2)]+(m[i][abs(s1-s2)]==-1?0:max(s1,s2));
    // }
    // int tallestBillboard(vector<int>& rods) {
    //     int sum=0,n=rods.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         sum+=rods[i];
    //     }
    //     int target=sum/2;
    //     vector<vector<int>>m(n,vector<int>(target+1,-2));
    //     return max(0,solve(0,0,0,target,m,rods));
    // }
    
     int tallestBillboard(vector<int>& rods) {
        unordered_map<int,int>dp;
         dp[0]=0;
         for(int i=0;i<rods.size();i++){
             unordered_map<int,int>cnt(dp);
             for(auto x: cnt){
                 int diff=x.first;
                 dp[diff+rods[i]]=max(dp[diff+rods[i]],cnt[diff]);
                 dp[abs(diff-rods[i])]=max(dp[abs(diff-rods[i])],cnt[diff]+min(rods[i],diff));
             }
         }
         return dp[0];
    }
};