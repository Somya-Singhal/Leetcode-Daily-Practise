class Solution {
public:
    int dp[6001][2];
    int jumps(int idx,unordered_set<int>& s, int a, int b, int x,int back)
    {
        if(idx==x)
            return 0;
        if(idx<0 || s.find(idx)!=s.end() || idx>6000) 
            return 1e5;
        if(dp[idx][back]!=-1)
            return dp[idx][back];
        dp[idx][back]=1+jumps(idx+a,s,a,b,x,0);
        if(!back)
        dp[idx][back]=min(dp[idx][back],1+jumps(idx-b,s,a,b,x,1));
        return dp[idx][back];
    }
    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_set<int>s;
        int n=forbidden.size();
        memset(dp,-1,sizeof dp);
        for(int i=0;i<n;i++)
            s.insert({forbidden[i]});
        return (jumps(0,s,a,b,x,1)>1e5)?-1:jumps(0,s,a,b,x,1);
    }
    
//     unordered_set<int>s;
    
    
//     int helper(int i, bool back , int a ,int b, int x) {
//         if(i == x)
//             return 0;
//         if(i<0 || i>6000 || back>=2 || s.find(i)!=s.end())
//             return 1e9;
//         // if(dp[i][back] != -1) 
//         //     return dp[i][back];
        
//         int curr = 1+helper(i+a,0,a,b,x); //go forward
        
//         if(!back) //cannot go consecutively backwards more than 1
//         {
//         curr = min(curr , helper(i-b,1,a,b,x)+1);  
        
//         }
//         return curr;
//     }
    

//     int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
//         for(int i=0;i<forbidden.size();i++){
//             s.insert({forbidden[i]});
//         }
//         // memset(dp,-1,sizeof(dp));
//         int ans = helper(0,0,a,b,x);
//         if(ans>1e9) 
//                return -1;
//         return ans;               
//     }
};