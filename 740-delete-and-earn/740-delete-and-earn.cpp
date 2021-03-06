class Solution {
public:
    //top-down-->time->O(N+k), spce->O(N+k)
    // int solve(unordered_map<int,int>& count,int maxnum,unordered_map<int,int>& cache)
    // {
    //     if(maxnum==0)
    //         return 0;
    //     if(maxnum==1)
    //         return count.find(1)!=count.end()?count[1]:0;
    //     if(cache.find(maxnum)!=cache.end())
    //         return cache[maxnum];
    //     if(count.find(maxnum)!=count.end())
    //     return cache[maxnum]=max(count[maxnum]+solve(count,maxnum-2,cache),solve(count,maxnum-1,cache));
    //     return cache[maxnum]=solve(count,maxnum-1,cache);
    // }
    // int deleteAndEarn(vector<int>& nums) {
    //     unordered_map<int,int>count,cache;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         count[nums[i]]++;
    //     }
    //     for(auto &x:count)
    //     {
    //         maxnum=max(maxnum,x.first);
    //        x.second*=x.first;
    //     }
    //     return solve(count,maxnum,cache);
    // }
    
    
    //bottom-up--->time->O(N+k), space->O(N+k)
    //  int deleteAndEarn(vector<int>& nums) {
    //     unordered_map<int,int>count;
    //     int n=nums.size();
    //      int maxnum=INT_MIN;
    //     for(int i=0;i<n;i++)
    //     {
    //         count[nums[i]]++;
    //     }
    //     for(auto &x:count)
    //     {
    //         maxnum=max(maxnum,x.first);
    //        x.second*=x.first;
    //     }
    //     vector<int>cache(maxnum+1,0);
    //     if(count.find(1)!=count.end())
    //     {
    //         cache[1]=count[1];
    //     }
    //      for(int i=2;i<=maxnum;i++)
    //      {
    //          if(count.find(i)!=count.end())
    //              cache[i]=max(count[i]+cache[i-2],cache[i-1]);
    //          else
    //              cache[i]=cache[i-1];
    //      }
    //     return cache[maxnum];
    // }
    
    //space-optimized bottom-up dp
    int deleteAndEarn(vector<int>& nums) {
        map<int,int>count;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            count[nums[i]]+=nums[i];
        }
        vector<int>keys;
        for(auto &x:count)
            keys.push_back(x.first);
        sort(keys.begin(),keys.end());
        int first=0,second=count[keys[0]];
         for(int i=1;i<keys.size();i++)
         {
             int curr;
             if(keys[i]==keys[i-1]+1)
                 curr=max(count[keys[i]]+first,second);
             else
                 curr+=count[keys[i]];
             first=second;
             second=curr;
         }
        return second;
    }
    
};