class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
       int total_max=INT_MIN;
        int ans=0;
        int n=piles.size();
        for(int i=0;i<n;i++)
        {
            total_max=max(total_max,piles[i]);
        }
        int lo=1,hi=total_max;
        while(lo<=hi){
           int mid=(lo+hi)/2,count=0;
            for(int i=0;i<n;i++)
            {
                count+=piles[i]/mid+(piles[i]%mid?1:0);
            }
            if(count<=h)
            {
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};