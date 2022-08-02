class Solution {
public:
    unordered_map<string,int>mp;
    int solve(int i,int sum,vector<int>& stones)
    {
        int n=stones.size();
        if(i==n && sum<0)
            return 5000;
        if(i==n)
            return 0;
        string str=to_string(i)+" "+to_string(sum);
        if(mp.find(str)!=mp.end())
            return mp[str];
        return mp[str]=min(-stones[i]+solve(i+1,sum-stones[i],stones),stones[i]+solve(i+1,sum+stones[i],stones));
    }
    int lastStoneWeightII(vector<int>& stones) {
        int n=stones.size();
        
        return solve(0,0,stones);
    }
};