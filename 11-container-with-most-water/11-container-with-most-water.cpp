class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo=0,hi=height.size()-1;
        int ans=INT_MIN;
        while(lo<hi)
        {
            ans=max(ans,(hi-lo)*min(height[hi],height[lo]));
            if(height[lo]<height[hi])
                lo++;
            else
                hi--;
        }
        return ans;
    }
};