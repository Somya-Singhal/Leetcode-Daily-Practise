class Solution {
public:
    long long mergeableArrays(vector<int>& arr1, vector<int>& arr2){
        long long result=0;
        int n1=arr1.size(), n2=arr2.size();
        int i=0,j=0;
        while(i<n1 && j<n2){
            if(arr1[i]<arr2[j]){
                result+=(n2-j);
                i++;
            } else{
                j++;
            }
        }
        return result;
    }
    long long incremovableSubarrayCount(vector<int>& nums) {
        int n=nums.size();
        if(n==1)
            return 1;
        int i=0,j=n-1;
        vector<int>arr1,arr2;
        while(i<n-1 && nums[i]<nums[i+1]){
            arr1.push_back(nums[i]);
            i+=1;
        }
        arr1.push_back(nums[i]);
        while(j>0 && nums[j]>nums[j-1]){
            arr2.push_back(nums[j]);
            j-=1;
        }
        arr2.push_back(nums[j]);
        reverse(arr2.begin(),arr2.end());
        if(j<i){
            long long ans=(1ll*n*(n+1)*1LL)/2;
            return ans;
        }
        long long ans=0;
        ans+=arr1.size();
        ans+=mergeableArrays(arr1,arr2);
        ans+=arr2.size();
        ans+=1;
        return ans;
    }
};