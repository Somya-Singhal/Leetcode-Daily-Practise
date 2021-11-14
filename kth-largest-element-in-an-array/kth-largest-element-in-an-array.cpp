class Solution {
public:
    // method-1(using min priority queue)
    /*
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int i=0;i<k;i++)
        {
            pq.push(nums[i]);
        }
        for(int i=k;i<n;i++)
        {
            if(nums[i]>=pq.top())
            {
                pq.pop();
                pq.push(nums[i]);
            }
        }
        return pq.top();
    }
    */
    // method-2(hoare's partitioning)
    int hoare(vector<int>& nums,int left,int right)
    {
        int l=left+1,r=right,pivot=nums[left];
        while(l<=r)
        {
            if(nums[l]<pivot && nums[r]>pivot)
                swap(nums[l++],nums[r--]);
            if(nums[l]>=pivot)
                l++;
            if(nums[r]<=pivot)
                r--;
        }
        swap(nums[left],nums[r]);
        return r;
    }
    int findKthLargest(vector<int>& nums, int k) {
        int n=nums.size();
        int low=0,high=n-1,idx=0;
        while(low<=high)
        {
            idx=hoare(nums,low,high);
            if(idx==k-1)
                break;
            else if(idx>k-1)
                high=idx-1;
            else
                low=idx+1;   
        }
        return nums[idx];
    }
};