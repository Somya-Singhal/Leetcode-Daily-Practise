class Solution {
public:
    //using array effectively
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        vector<int>res;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            int index=abs(nums[i])-1;
                nums[index]=-abs(nums[index]);
        }
        for(int i=0;i<n;i++)
        {
            if(nums[i]>0)
                res.push_back(i+1);
        }
        return res;
    }
};