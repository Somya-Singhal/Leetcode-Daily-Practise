class Solution {
public:
    void merge(int lo,int mid,int hi,vector<pair<int,int>>& temp,vector<int>& ans)
    {
        int i=lo,j=mid+1,k=0;
        vector<pair<int,int>>v(hi-lo+1);
        while(i<=mid && j<=hi)
        {
            if(temp[i].first<=temp[j].first)
            {
                v[k++]=temp[j++];
            }
            else{
                ans[temp[i].second]+=hi-j+1;
                v[k++]=temp[i++];
            }
        }
        while(i<=mid)
        {
            v[k++]=temp[i++];
        }
        while(j<=hi)
        {
            v[k++]=temp[j++];
        }
        for(int i=lo;i<=hi;i++)
            temp[i]=v[i-lo];
    }
    void mergeSort(int lo,int hi,vector<pair<int,int>>& temp,vector<int>& ans)
    {
        if(lo<hi)
        {
            int mid=lo+(hi-lo)/2;
            mergeSort(lo,mid,temp,ans);
            mergeSort(mid+1,hi,temp,ans);
            merge(lo,mid,hi,temp,ans);
        }
    }
    vector<int> countSmaller(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        vector<pair<int,int>>temp;
        for(int i=0;i<n;i++)
        {
            temp.push_back({nums[i],i});
        }
        mergeSort(0,n-1,temp,ans);
        return ans;
    }
};