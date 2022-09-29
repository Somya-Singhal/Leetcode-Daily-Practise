class Solution {
public:
    // vector<int> findClosestElements(vector<int>& arr, int k, int x) {
    //     map<int,multiset<int>>m;
    //     vector<int>ans;
    //     int n=arr.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         m[abs(arr[i]-x)].insert(arr[i]);
    //     }
    //     for(auto x: m)
    //     {
    //         if(ans.size()==k)
    //             break;
    //         for(auto y: x.second)
    //         {
    //             ans.push_back(y);
    //             if(ans.size()==k)
    //                 break;
    //         }
    //     }
    //     sort(ans.begin(),ans.end());
    //     return ans;
    // }
    
     vector<int> findClosestElements(vector<int>& arr, int k, int x) {
       int n=arr.size();
       int left=0,right=n-k;
       while(left<right)
       {
           int mid=(left+right)/2;
           if(x-arr[mid]>arr[mid+k]-x)
               left=mid+1;
           else
               right=mid;
       }
      return vector<int>(arr.begin()+left,arr.begin()+left+k);
         
    }
};