class Solution {
public:
    // unbounded knapsack
    
    // recursive--->
    void sumrec(vector<int>& candidates,vector<int>& v,int target,int n,vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(v);
            return;
        }
        if(n==0)
            return;
        if(candidates[n-1]<=target)
        {
            v.push_back(candidates[n-1]);
            sumrec(candidates,v,target-candidates[n-1],n,res);
            v.pop_back();
            sumrec(candidates,v,target,n-1,res);
        }
        else{
           sumrec(candidates,v,target,n-1,res); 
        }
    } 
    
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>v;
        int n=candidates.size();
        sumrec(candidates,v,target,n,res);
        return res;
    }
};