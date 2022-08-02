class Solution {
public:
//     unordered_map<string,int>mp;
//     int solve(int i,int sum,vector<int>& stones)
//     {
//         int n=stones.size();
//         if(i==n && sum<0)
//             return 5000;
//         if(i==n)
//             return 0;
//         string str=to_string(i)+" "+to_string(sum);
//         if(mp.find(str)!=mp.end())
//             return mp[str];
//         return mp[str]=min(-stones[i]+solve(i+1,sum-stones[i],stones),stones[i]+solve(i+1,sum+stones[i],stones));
//     }
//     int lastStoneWeightII(vector<int>& stones) {
//         int n=stones.size();
        
//         return solve(0,0,stones);
//     }
    
     int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        int tsum=0;
        for(int i=0;i<n;i++)
            tsum+=stones[i];
        bool dp[tsum+1];
        for(int i=0;i<=tsum;i++)
            dp[i]=false;
        dp[0]=true;
        int sum=0;
        for(int i=0;i<n;i++)
        {
            sum+=stones[i];
            for(int j=min(sum,tsum);j>=stones[i];j--)
                dp[j] |= dp[j-stones[i]];
        }
        for(int i=sum/2;i>=0;i--)
        {
            if(dp[i])
                return sum-2*i;
        }
        return 0;
    }
};