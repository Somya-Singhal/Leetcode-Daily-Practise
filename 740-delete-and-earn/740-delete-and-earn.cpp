class Solution {
public:
    int solve(unordered_map<int,int>& count,int maxnum,unordered_map<int,int>& cache)
    {
        if(maxnum==0)
            return 0;
        if(maxnum==1)
            return count.find(1)!=count.end()?count[1]:0;
        if(cache.find(maxnum)!=cache.end())
            return cache[maxnum];
        if(count.find(maxnum)!=count.end())
        return cache[maxnum]=max(count[maxnum]+solve(count,maxnum-2,cache),solve(count,maxnum-1,cache));
        return cache[maxnum]=solve(count,maxnum-1,cache);
    }
    int deleteAndEarn(vector<int>& nums) {
        unordered_map<int,int>count,cache;
        int n=nums.size();
        int maxnum=INT_MIN;
        for(int i=0;i<n;i++)
        {
            count[nums[i]]++;
        }
        for(auto &x:count)
        {
            maxnum=max(maxnum,x.first);
           x.second*=x.first;
        }
        return solve(count,maxnum,cache);
    }
};