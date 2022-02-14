class Solution {
public:
    void wiggleSort(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        vector<int>temp(n,0);
        int i=1,j=n-1;
        while(i<n)
        {
            temp[i]=nums[j];
            i=i+2;
            j--;
        }
        i=0;
        while(i<n)
        {
            temp[i]=nums[j];
            j--;
            i=i+2;
        }
        nums=temp;
        return;
    }
};