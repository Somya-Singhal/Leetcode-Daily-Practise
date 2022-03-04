class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        int n=nums.size();
        if(n<3)
            return 0;
        int prevdiff=nums[1]-nums[0],start=0,end=0;
        int ans=0,currdiff;
        for(int i=1;i<n;i++)
        {
            currdiff=nums[i]-nums[i-1];
            if(currdiff==prevdiff)
               end++;
            else
            {
                if(end-start+1>=3)
                {
                    int len=end-start+1;
                    ans+=(len-3+1)+(len-3+1)*len-(len*(len+1)/2-3);
                }
                start=i-1,end=i;
                prevdiff=currdiff;
            }
        }
        if(currdiff==prevdiff)
        {
            int len=end-start+1;
            ans+=(len-3+1)+(len-3+1)*len-(len*(len+1)/2-3);
        }
        return ans;
    }
};