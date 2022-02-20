class Solution {
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n=intervals.size();
        int ans=1;
        vector<int>res=intervals[0];
        for(int i=1;i<n;i++)
        {
            if(intervals[i][1]>res[1] && intervals[i][0]>res[0])
            {
                res=intervals[i];
                ans++;
            }
            else{
                res[0]=min(res[0],intervals[i][0]);
                res[1]=max(res[1],intervals[i][1]);
            }
        }
        return ans;
    }
};