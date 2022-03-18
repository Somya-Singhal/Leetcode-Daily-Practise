class Solution {
public:
    int diff=INT_MAX;
    void solve(int idx,int curr,int &best,vector<int>& toppingCosts,int target)
    {
        if(curr>=target || idx>=toppingCosts.size())
        {
            if(abs(target-curr)<abs(target-best))
                best=curr;
            if(abs(target-curr)==abs(target-best))
                best=min(best,curr);
            return;
        }
        for(int i=0;i<=2;i++)
        {
           solve(idx+1,curr+i*toppingCosts[idx],best,toppingCosts,target);
        }
    }
    int closestCost(vector<int>& baseCosts, vector<int>& toppingCosts, int target) {
        int ans=INT_MAX;
        int b=baseCosts.size();
        for(int i=0;i<b;i++)
        solve(0,baseCosts[i],ans,toppingCosts,target);        
        return ans;
    }
};