class Solution {
public:
    //brute force
    //time->O(nk)
    // bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
    //     int n=nums.size();
    //     unordered_set<int>s(nums.begin(),nums.end());
    //     if(t==0 && s.size()==n)
    //         return 0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+1;j<i+1+k && j<n;j++)
    //         {
    //             if(abs((long long)nums[i]-nums[j])<=t)
    //                 return true;
    //         }
    //     }
    //     return false;
    // }
    
     bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
       int n=nums.size();
       set<long long>window;
        for(long long i=0;i<n;i++)
        {
           long long n1=nums[i];
           if(i>k)
               window.erase(nums[i-k-1]);
           auto pos=window.lower_bound(n1-t);
            if(pos!=window.end() && *pos-n1<=t)
                return true;
            window.insert({n1});
        }
        return false;
    }
};