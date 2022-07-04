class Solution {
public:
    void sortColors(vector<int>& nums) {
      // int freq[3]={0};
      //   for(int i=0;i<nums.size();i++)
      //   {
      //       freq[nums[i]]++;
      //   }
      //   int j=0;
      //   for(int i=0;i<3;i++)
      //   {
      //       while(freq[i]>0)
      //       {
      //           nums[j++]=i;
      //           freq[i]--;
      //       }
      //   }
        int n=nums.size();
        int lo=0,mid=0,hi=n-1;
        while(mid<=hi)
        {
            if(nums[mid]==0)
            {
                swap(nums[lo++],nums[mid++]);
            }
            else if(nums[mid]==1)
            {
                mid++;
            }
            else
            {
                swap(nums[mid],nums[hi--]);
            }
        }
    }
};