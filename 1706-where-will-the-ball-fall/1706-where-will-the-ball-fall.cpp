class Solution {
public:
    vector<int> findBall(vector<vector<int>>& grid) {
        int row=grid.size(),col=grid[0].size();
        vector<int>ans;
        for(int i=0;i<col;i++)
        {
            int curr=i;
            for(int j=0;j<row;j++)
            {
                int next=curr+grid[j][curr];
                if(next<0 || next>=col || grid[j][next]!=grid[j][curr])
                {
                    curr=-1;
                    break;
                }
                curr=next;
            }
            ans.push_back(curr);
        }
        return ans;
    }
};