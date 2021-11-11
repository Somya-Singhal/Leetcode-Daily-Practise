class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums1.size()>nums2.size())
            swap(nums1,nums2);
        int n1=nums1.size(),n2=nums2.size();
        int low=0,high=n1;
        double res;
        while(low<=high)
        {
            int mid1=(low+high)/2;
            int mid2=(n1+n2)/2-mid1;
            int l1=(mid1==0)?INT_MIN:nums1[mid1-1];
            int l2=(mid2==0)?INT_MIN:nums2[mid2-1];
            int r1=(mid1==n1)?INT_MAX:nums1[mid1];
            int r2=(mid2==n2)?INT_MAX:nums2[mid2];
            if(l1<=r2 && l2<=r1)
            {
                if((n1+n2)%2==0)
                    res=(double)(max(l1,l2)+min(r1,r2))/2;
                else
                    res=(double)(min(r1,r2));
                break;
            }   
            else if(l1>r2)
            high=mid1-1;
            else
            low=mid1+1;
        }
        return res;
    }
};