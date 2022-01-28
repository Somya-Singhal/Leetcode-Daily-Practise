class Solution {
public:
    // int jumps(int idx,unordered_set<int>& s, int a, int b, int x,bool back)
    // {
    //     if(idx==x)
    //         return 0;
    //     if(idx<0 || s.find(idx)!=s.end() || idx>6000 || back>=2) 
    //         return 1e9;
    //     int curr=0;
    //     curr=1+jumps(idx+a,s,a,b,x,0);
    //     if(!back)
    //     curr=min(curr,jumps(idx-b,s,a,b,x,1)+1);
    //     return curr;
    // }
    // int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
    //     unordered_set<int>s;
    //     int n=forbidden.size();
    //     for(int i=0;i<n;i++)
    //         s.insert({forbidden[i]});
    //     int ans=jumps(0,s,a,b,x,false);
    //     if(ans>1e9)
    //         return -1;
    //    return ans;
    // }
    
    unordered_map<int,int> mp;
    int dp[6001][2];
    
    
    int helper(int i, bool back , int a ,int b, int x) {
        if(i == x)
            return 0;
        if(i<0 || i>6000 || back>=2 || mp.find(i)!=mp.end())
            return 1e9;
        if(dp[i][back] != -1) 
            return dp[i][back];
        
        dp[i][back] = 1+helper(i+a,0,a,b,x); //go forward
        
        if(!back) //cannot go consecutively backwards more than 1
        {
        dp[i][back] = min(dp[i][back] , helper(i-b,1,a,b,x)+1);  
        
        }
        return dp[i][back];
    }
    

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        for(int i=0;i<forbidden.size();i++){
            mp[forbidden[i]] = 1;
        }
        memset(dp,-1,sizeof(dp));
        int ans = helper(0,0,a,b,x);
        if(ans>1e9) 
               return -1;
        return ans;               
    }
};