class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int a=0,b=cost[0];
        int ans=0;
        for(int i=1;i<cost.size();i++)
        {
            int temp=b;
            b=min(a,b)+cost[i];
            a=temp;
        }
        return min(a,b);
    }
};