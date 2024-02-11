class Solution {
public:
    int jump(vector<int>& nums) {
        int lastjump=0,coverage=0,n=nums.size(),steps=0;
        int destination=n-1;
        if(n==1)
            return 0;
        for(int i=0;i<n;i++){
            coverage = max(coverage, i+nums[i]);
            if(i==lastjump){
                lastjump=coverage;
                steps++;
                if(lastjump>=destination){
                    return steps;
                }
            }
            
        }
        return steps;
    }
};