class Solution {
public:
    int minimizedMaximum(int n, vector<int>& quantities) {
        int total_max=INT_MIN;
        int q=quantities.size();
        for(int i=0;i<q;i++)
            total_max=max(total_max,quantities[i]);
        long long lo=1,hi=total_max;
        // cout<<lo<<" "<<hi;
        int ans=0;
        while(lo<=hi) {
            long long mid=(lo+hi)/2;
            int count=0;
            for(int i=0;i<q;i++)
            {
                count+=quantities[i]/mid+((quantities[i]%mid)?1:0);
            }
            if(count<=n)
            {
                ans=mid;
                hi=mid-1;
            }
            else
                lo=mid+1;
        }
        return ans;
    }
};