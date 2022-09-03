class Solution {
public:
    
//     int solve(int left,int right,map<pair<int,int>,int>& mp)
//     {
//         if(left==right)
//             return 0;
        
//         int ans=INT_MAX;
//         for(int k=left;k<right;k++)
//         {
//            ans=min(ans,mp[{left,k}]*mp[{k+1,right}]+solve(left,k,mp)+solve(k+1,right,mp));
//         }
//         return ans;
//     }
//     int mctFromLeafValues(vector<int>& arr) {
//         int n=arr.size();
//         map<pair<int,int>,int>mp;
//         for(int i=0;i<n;i++)
//         {
//             mp[{i,i}]=arr[i];
//             for(int j=i+1;j<n;j++)
//             {
//                 mp[{i,j}]=max(mp[{i,j-1}],arr[j]);
//             }
//         }
//         return solve(0,n-1,mp);
//     }
    
 
    // int solve(int left,int right,map<pair<int,int>,int>& mp,vector<vector<int>>& dp)
    // {
    //     if(left==right)
    //         return 0;
    //     if(dp[left][right]!=-1)
    //         return dp[left][right];
    //     int ans=INT_MAX;
    //     for(int k=left;k<right;k++)
    //     {
    //        ans=min(ans,mp[{left,k}]*mp[{k+1,right}]+solve(left,k,mp,dp)+solve(k+1,right,mp,dp));
    //     }
    //     return dp[left][right]=ans;
    // }
    //  int mctFromLeafValues(vector<int>& arr) {
    //     int n=arr.size();
    //     map<pair<int,int>,int>mp;
    //     vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[{i,i}]=arr[i];
    //         for(int j=i+1;j<n;j++)
    //         {
    //             mp[{i,j}]=max(mp[{i,j-1}],arr[j]);
    //         }
    //     }
    //     return solve(0,n-1,mp,dp);
    // }
    
     int mctFromLeafValues(vector<int>& arr) {
        int n=arr.size();
        int ans=0;
        stack<int>s;
        s.push(INT_MAX);
        for(int i=0;i<n;i++)
        {
            while(s.top()<=arr[i])
            {
                int curr=s.top();
                s.pop();
                ans+=curr*min(s.top(),arr[i]);
            }
            s.push(arr[i]);
        }
        while(s.size()>2)
        {
            int curr=s.top();
            s.pop();
            ans+=curr*s.top();
        }
         return ans;
    }
};