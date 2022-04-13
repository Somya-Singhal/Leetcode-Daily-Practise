class Solution {
public:
    // void dfs(vector<int>& nums,int s,int e,int n,int sum,vector<vector<int>>&sums){
    //     if(s==e || n==nums.size()/4)
    //         sums[n].push_back(sum);
    //     else{
    //         dfs(nums,s+1,e,n,sum,sums);
    //         dfs(nums,s+1,e,n+1,sum+nums[s],sums);
    //     }
    // }
    // int minimumDifference(vector<int>& nums) {
    //     int n=nums.size()/2,n2=n/2;
    //     int sum1=0,sum2=0;
    //     int res=INT_MAX;
    //     for(int i=0;i<n;i++)
    //         sum1+=nums[i];
    //     for(int i=n;i<nums.size();i++)
    //         sum2+=nums[i];
    //     vector<vector<int>>s1(n+1),s2(n+1);
    //     dfs(nums,0,n,0,0,s1);
    //     dfs(nums,n,2*n,0,0,s2);
    //     for(int k=0;k<=n2;k++){
    //         for(int s1k: s1[k]){
    //             sort(s2[k].begin(),s2[k].end());
    //             int comp=(sum1+sum2)/2-(sum1-s1k),diff=sum1-sum2-s1k*2;
    //             int j=lower_bound(s2[k].begin(),s2[k].end(),comp)-s2[k].begin();
    //             if(j<s2[k].size())
    //               res=min(res,abs(diff+2*s2[k][j]));
    //             if(j>0)
    //                 res=min(res,abs(diff+2*s2[k][j-1]));
    //         }
    //     }
    //     return res;
    // }
    
    
    //        vector<int>left_v,right_v;
//          for(int i=0;i<n;i++){
//              sum+=nums[i];
//              if(i<n1)
//              {
//                  ls+=nums[i];
//                  left_v.push_back(nums[i]);
//              }
//              else
//              {
//                  rs+=nums[i];
//                  right_v.push_back(nums[i]);
//              }
                
//          }
    
    //  int minimumDifference(vector<int>& nums) {
    //    int n=nums.size();
    //    int n1=n/2,sum=0,res=0;
    //      for(int i=0;i<n;i++)
    //          sum+=nums[i];
    //      vector<vector<int>>left_sum(n1+1),right_sum(n1+1);
    //       for(int mask=0;mask<(1<<n1);mask++){
    //          int len=0,l=0,r=0;
    //          for(int i=0;i<n1;i++){
    //              if(mask&(1<<i))
    //              {
    //                  len++;
    //                  l+=nums[i];
    //                  r+=nums[n1+i];
    //              }
    //          }
    //           left_sum[len].push_back(l);
    //           right_sum[len].push_back(r);
    //       }
    //      for(int i=0;i<=n1;i++)
    //          sort(right_sum[i].begin(),right_sum[i].end());
    //       res=min(abs(sum-2*left_sum[n1][0]),abs(sum-2*right_sum[n1][0]));
    //          for(int sz=1;sz<n1;sz++){
    //              for(int x:left_sum[sz]){
    //                  int a=(sum-2*x)/2,y=n1-sz;
    //                  auto comp=lower_bound(right_sum[y].begin(),right_sum[y].end(),a);
    //                  if(comp!=right_sum[y].end())
    //                  {
    //                      // int left=x+*comp;
    //                      // int right=sum-left;
    //                      // res=min(res,abs(left-right));
    //                       res=min(res,abs(sum-2*(x+*comp)));
    //                  }
    //                  if(comp!=right_sum[y].begin()){
    //                     auto it=comp;
    //                     --it;
    //                      res=min(res,abs(sum-2*(x+*it)));
    //                  }
    //              }
    //          } 
    //     return res; 
    // }
    
    int minimumDifference(vector<int>& nums) {
       int n=nums.size();
       int n1=n/2,sum=0,res=0;
         for(int i=0;i<n;i++)
             sum+=nums[i];
         vector<vector<int>>left_sum(n1+1),right_sum(n1+1);
          for(int mask=0;mask<(1<<n1);mask++){
             int len=0,l=0,r=0;
             for(int i=0;i<n1;i++){
                 if(mask&(1<<i))
                 {
                     len++;
                     l+=nums[i];
                     r+=nums[n1+i];
                 }
             }
              left_sum[len].push_back(l);
              right_sum[len].push_back(r);
          }
         for(int i=0;i<=n1;i++)
             sort(right_sum[i].begin(),right_sum[i].end());
          res=min(abs(sum-2*left_sum[n1][0]),abs(sum-2*right_sum[n1][0]));
             for(int sz=1;sz<n1;sz++){
                 for(int x:left_sum[sz]){
                     int a=(sum-2*x)/2,y=n1-sz;
                     auto comp=lower_bound(right_sum[y].begin(),right_sum[y].end(),a);
                     if(comp!=right_sum[y].end())
                     {
                         // int left=x+*comp;
                         // int right=sum-left;
                         // res=min(res,abs(left-right));
                          res=min(res,abs(sum-2*(x+*comp)));
                     }
                     // if(comp!=right_sum[y].begin()){
                     //    auto it=comp;
                     //    --it;
                     //     res=min(res,abs(sum-2*(x+*it)));
                     // }
                 }
             } 
        return res; 
    }
};