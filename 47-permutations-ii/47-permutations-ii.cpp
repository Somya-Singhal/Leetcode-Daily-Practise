class Solution {
public:
    void solve(vector<vector<int>>& res,int n,vector<int>& comb,unordered_map<int,int>& mp)
    {
        if(comb.size()==n)
        {
            res.push_back(comb);
            return;
        }
        for(auto &x: mp){
            int num=x.first;
            int count=x.second;
            if(count==0)
                continue;
            mp[x.first]--;
            comb.push_back(x.first);
            solve(res,n,comb,mp);
            comb.pop_back();
            mp[x.first]=count;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
            mp[nums[i]]++;
        }
        vector<vector<int>>res;
        vector<int>comb;
        solve(res,n,comb,mp);
        return res;
    }
};