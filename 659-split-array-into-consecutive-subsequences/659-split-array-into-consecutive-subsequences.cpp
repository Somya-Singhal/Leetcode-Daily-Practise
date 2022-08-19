class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>left,end;
        for(int i=0;i<n;i++)
            left[nums[i]]++;
        for(int i=0;i<n;i++)
        {
            if(left[nums[i]]==0)
                continue;
            left[nums[i]]--;
            if(end[nums[i]-1]>0)
            {
                end[nums[i]-1]--;
                end[nums[i]]++;
            }
            else if(left[nums[i]+1]>0 && left[nums[i]+2]>0)
            {
                left[nums[i]+1]--;
                left[nums[i]+2]--;
                end[nums[i]+2]++;
            }
            else
                return false;
        }
        return true;
    }
};