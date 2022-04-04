class Solution {
public:
  
    int maximumCandies(vector<int>& candies, long long k) {
        int n=candies.size();
        long long lo=0,hi=1e7;
        while(lo<hi)
        {
            long long mid=(lo+hi+1)/2,num=0;
            for(int i=0;i<n && num<k;i++)
            {
                num+=candies[i]/mid;
            }
            if(num>=k)
            {
                lo=mid;
            }
            else
                hi=mid-1;
        }
        return lo;
    }
};