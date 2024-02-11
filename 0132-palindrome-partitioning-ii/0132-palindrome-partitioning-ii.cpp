class Solution {
public:
    // bool isPalindrome(string s,int i,int j){
    //     int lo=i,hi=j;
    //     while(lo<hi){
    //         if(s[lo]!=s[hi]){
    //             return false;
    //         } else{
    //             lo++;
    //             hi--;
    //         }
    //     }
    //     return true;
    // }
    int minCut(string s) {
        int n=s.length();
        vector<int>dp(n+1,-1);
        vector<vector<int>>ispalin(n,vector<int>(n,0));
        dp[n]=0;
        for(int i=n-1;i>=0;i--){
            int cuts=INT_MAX;
            for(int k=i;k<n;k++){
                if(s[i]==s[k] && (k-i<2 || ispalin[i+1][k-1])){
                    ispalin[i][k]=1;
                    cuts=min(cuts,1+dp[k+1]);
                }
            }
            dp[i]=cuts;
        }
        return dp[0]-1;
    }
    
};