class Solution {
public:
    // bool solve(int i,string s,unordered_set<string>& dict,vector<bool>& dp){
    //     int n=s.length();
    //     if(i==n)
    //         return true;
    //     if(dp[i])
    //         return dp[i];
    //     for(int j=i;j<n;j++){
    //         if(dict.find(s.substr(i,j+1-i))!=dict.end() && solve(j+1,s,dict,dp)){
    //             return dp[i]=true;
    //         }
    //     }
    //     return dp[i]=false;
    // }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string>dict;
        int len=s.length();
        vector<bool>dp(len+1,false);
        int n=wordDict.size();
        for(int i=0;i<n;i++){
            dict.insert(wordDict[i]);
        }
        dp[len]=true;
        for(int i=len-1;i>=0;i--){
            dp[i]=false;
            for(int j=i;j<len;j++){
            if(dict.find(s.substr(i,j+1-i))!=dict.end() && dp[j+1]){
                dp[i]=true;
                break;
            }
          }
        }
        return dp[0];
    }
};