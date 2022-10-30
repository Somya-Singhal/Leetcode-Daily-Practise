class Solution {
public:
    struct Job
    {
        int start,end,cost;
    };
    static bool comparator(Job &p1,Job &p2)
    {
        if(p1.end==p2.end)
            return p1.start<p2.start;
        return p1.end<p2.end;
    }
    int findNonOverlapping(vector<Job>& intervals,int i)
    {
    
        for(int j=i-1;j>=0;j--)
        {
            if(intervals[j].end<=intervals[i].start)
                return j;
        }
        return -1;
    }
    int solve(vector<Job>& intervals,vector<int>& dp,int i)
    {
        int n=intervals.size();
        if(i==0)
            return intervals[i].cost;
        if(dp[i]!=-1)
            return dp[i];
        int excluded=solve(intervals,dp,i-1);
        int included=intervals[i].cost;
        int idx=findNonOverlapping(intervals,i);
        if(idx!=-1)
        included+=solve(intervals,dp,idx);
        dp[i]=max(excluded,included);
        return dp[i];
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime, vector<int>& profit) {
        vector<Job>intervals;
        int n=startTime.size();
        vector<int>dp(n+1,-1);
        for(int i=0;i<n;i++)
        {
            intervals.push_back({startTime[i],endTime[i],profit[i]});
        }
        sort(intervals.begin(),intervals.end(),comparator);
        return solve(intervals,dp,n-1);
    }
};