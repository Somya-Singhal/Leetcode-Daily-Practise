class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>res;
        sort(intervals.begin(),intervals.end());
        int i=0;
        int n=intervals.size();
        for(int j=1;j<n;j++)
        {
            if(intervals[j][0]<=intervals[i][1])
                intervals[i][1]=max(intervals[i][1],intervals[j][1]);
            else
            {
                res.push_back(intervals[i]);
                i=j;
            }
        }
        res.push_back(intervals[i]);
        return res;
    }
};