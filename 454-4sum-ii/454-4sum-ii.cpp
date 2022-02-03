class Solution {
public:
    int fourSumCount(vector<int>& nums1, vector<int>& nums2, vector<int>& nums3, vector<int>& nums4) {
        unordered_map<int,int>m1,m2;
        int n1=nums1.size(),n2=nums2.size(),n3=nums3.size(),n4=nums4.size();
        int count=0;
        for(int i=0;i<n1;i++)
        {
            for(int j=0;j<n2;j++)
            {
                int sum=nums1[i]+nums2[j];
                m1[sum]++;
            }
        }
        for(int i=0;i<n3;i++)
        {
            for(int j=0;j<n4;j++)
            {
                int sum=nums3[i]+nums4[j];
                m2[sum]++;
            }
        }
        for(auto x:m1)
        {
            if(m2.find(-x.first)!=m2.end())
                count+=x.second*m2[-x.first];
        }
        return count;
    }
};