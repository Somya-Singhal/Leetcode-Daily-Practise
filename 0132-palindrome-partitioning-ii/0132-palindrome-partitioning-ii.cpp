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
    // int minCut(string s) {
    //     int n=s.length();
    //     vector<int>dp(n+1,-1);
    //     dp[n]=0;
    //     for(int i=n-1;i>=0;i--){
    //         int cuts=INT_MAX;
    //         for(int k=i;k<n;k++){
    //             if(isPalindrome(s,i,k)){
    //                 cuts=min(cuts,1+dp[k+1]);
    //             }
    //         }
    //         dp[i]=cuts;
    //     }
    //     return dp[0]-1;
    // }
    
    int minCut(string s) {
        int n=s.length();
        vector<vector<bool>>checkpalin(n,vector<bool>(n,false));
        vector<int>count(n);
        
        //constructing boolean matrix to find which substring is palindrome
        for(int i=0;i<n;i++)
        {
            int mincut=i;
            for(int j=0;j<=i;j++)
            {
                if(s[i]==s[j] &&((i-j)<2 || checkpalin[j+1][i-1]))
                {
                    checkpalin[j][i]=true;
                    mincut=min(mincut,(j==0)?0:count[j-1]+1);
                }
            }
            count[i]=mincut;
        }
        return count[n-1];
    }
};