class Solution {
public:
    // void solve(int idx,vector<int>& candidates,int target,int n,int sum,vector<vector<int>>& res,vector<int>& v)
    // {
    //     if(sum==target)
    //     {
    //         res.push_back(v);
    //         return;
    //     }
    //     if(idx==n || sum>target)
    //     return;
    //     v.push_back(candidates[idx]);
    //     solve(idx+1,candidates,target,n,sum+candidates[idx],res,v);
    //     v.pop_back();
    //     solve(idx+1,candidates,target,n,sum,res,v);
    //     return;
    // }
    // vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    //     int n=candidates.size();
    //     vector<int>v;
    //     vector<vector<int>>res;
    //     solve(0,candidates,target,n,0,res,v);
    //     set<vector<int>>s;
    //     for(auto x: res)
    //     {
    //         sort(x.begin(),x.end());
    //         s.insert(x);
    //     }
    //     res.clear();
    //     for(auto x: s)
    //     {
    //         res.push_back(x);
    //     }
    //     return res;
    // }
    
     void solve(int idx,vector<int>& candidates, int target,int n,int sum,vector<vector<int>>& res,vector<int>& v)
    {
        if(sum==target)
        {
            res.push_back(v);
            return;
        }
        if(sum>target)
        return;
        for(int s=idx;s<n;s++)
        {
            if(s>idx && candidates[s]==candidates[s-1])
                continue;
            if(candidates[s]>target)
                break;
            v.push_back(candidates[s]);
            solve(s+1,candidates,target,n,sum+candidates[s],res,v);
            v.pop_back();     
        }
        return;
    }
     vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        int n=candidates.size();
        sort(candidates.begin(),candidates.end());
        vector<int>v;
        vector<vector<int>>res;
        solve(0,candidates,target,n,0,res,v);
        return res;
    }
};