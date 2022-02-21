class Solution {
public:
    // void solve(vector<vector<int>>& res,int n,vector<int>& comb,unordered_map<int,int>& mp)
    // {
    //     if(comb.size()==n)
    //     {
    //         res.push_back(comb);
    //         return;
    //     }
    //     for(auto &x: mp){
    //         int num=x.first;
    //         int count=x.second;
    //         if(count==0)
    //             continue;
    //         mp[x.first]--;
    //         comb.push_back(x.first);
    //         solve(res,n,comb,mp);
    //         comb.pop_back();
    //         mp[x.first]=count;
    //     }
    // }
    // vector<vector<int>> permuteUnique(vector<int>& nums) {
    //     int n=nums.size();
    //     unordered_map<int,int>mp;
    //     for(int i=0;i<n;i++)
    //     {
    //         mp[nums[i]]++;
    //     }
    //     vector<vector<int>>res;
    //     vector<int>comb;
    //     solve(res,n,comb,mp);
    //     return res;
    // }
    
     void solve(vector<vector<int>>& res,int n,vector<int>& comb,vector<int>& flag,vector<int>& nums)
     {
         if(comb.size()==n)
         {
             res.push_back(comb);
             return;
         }
         for(int i=0;i<n;i++)
         {
             if(flag[i]==1)
                 continue;
             if(i>0 && nums[i-1]==nums[i] && flag[i-1]==0)
                 continue;
             flag[i]=1;
             comb.push_back(nums[i]);
             solve(res,n,comb,flag,nums);
             flag[i]=0;
             comb.pop_back();
         }
     }
     vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<vector<int>>res;
        vector<int>flag(n,0);
        vector<int>comb;
        solve(res,n,comb,flag,nums);
        return res;
    }
};