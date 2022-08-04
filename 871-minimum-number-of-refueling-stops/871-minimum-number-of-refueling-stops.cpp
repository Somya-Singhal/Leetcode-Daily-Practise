class Solution {
public:
//     unordered_map<string,int>mp;
//     int solve(int i,int prev,int target, int startFuel, vector<vector<int>>& stations)
//     {
//         int n=stations.size();
//         if(i==n || startFuel<stations[i][0])
//             return INT_MAX-1;
//         if(target<=0)
//             return 0;
        
//         string str=to_string(i)+" "+to_string(prev)+" "+to_string(target)+" "+to_string(startFuel);
//         if(mp.find(str)!=mp.end())
//             return mp[str];
//         if(startFuel==stations[i][0])
//             return mp[str]=1+solve(i+1,stations[i][0],target-prev,stations[i][1],stations);
//         return mp[str]=min(1+solve(i+1,stations[i][0],target-prev,startFuel-prev+stations[i][1],stations),solve(i+1,prev,target,startFuel,stations));
//     }
//     int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
//         int ans=solve(0,0,target,startFuel,stations);
//         int n=stations.size();
//         sort(stations.begin(),stations.end());
        
//         return ans==INT_MAX-1?-1:ans;
//     }
    
    
    //  int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
    //    int n=stations.size();
    //    vector<long long>dp(n+1,0);
    //     dp[0]=startFuel;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i;j>=0;j--)
    //         {
    //             if(dp[j]>=stations[i][0])
    //                 dp[j+1]=max(dp[j+1],dp[j]+stations[i][1]);
    //         }
    //     }
    //     for(int i=0;i<=n;i++)
    //     {
    //         if(dp[i]>=target)
    //             return i;
    //     }
    //      return -1;
    // }
    
    int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
       int n=stations.size();
       // if(n==0)
       //      return (startFuel>=target?0:-1);
       priority_queue<int>pq;
       int curr=startFuel,res=0,i=0;
       while(curr<target)
       {
           while(i<n && stations[i][0]<=curr)
           {
               pq.push(stations[i][1]);
               i++;
           }
           if(pq.empty())
               return -1;
           curr+=pq.top();
           res++;
           pq.pop();
       }
        
       return res;
    }
};