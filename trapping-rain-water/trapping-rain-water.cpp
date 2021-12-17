class Solution {
public:
    //dp-->O(n)
    // int trap(vector<int>& height) {
    //     int n=height.size();
    //     int left[n];
    //     int right[n];
    //     int ans=0;
    //     left[0]=height[0];
    //     right[n-1]=height[n-1];
    //     for(int i=1;i<n;i++)
    //     {
    //         left[i]=max(left[i-1],height[i]);
    //     }
    //     for(int i=n-2;i>=0;i--)
    //     {
    //         right[i]=max(right[i+1],height[i]);
    //     }
    //     for(int i=1;i<n-1;i++)
    //     {
    //         ans+=min(left[i],right[i])-height[i];
    //     }
    //     return ans;
    // }
    
    //stack-->O(n)
    //  int trap(vector<int>& height) {
    //     int n=height.size();
    //     stack<int>st;
    //     int curr=0,ans=0;
    //     while(curr<n)
    //     {
    //        while(!st.empty() && height[curr]>height[st.top()]) 
    //        {
    //            int top=st.top();
    //            st.pop();
    //            if(st.empty())
    //                break;
    //            int distance=curr-st.top()-1;
    //            ans+=distance*(min(height[curr],height[st.top()])-height[top]);
    //        }
    //       st.push(curr++);
    //     }
    //    return ans;
    // }
    //two pointers-->O(n)
     int trap(vector<int>& height) {
        int n=height.size();
        int left=0,right=n-1;
         int ans=0;
         int left_max=INT_MIN,right_max=INT_MIN;
        while(left<right)
        {
           if(height[left]<height[right])
           {
               if(height[left]>=left_max)
                   left_max=height[left];
               else
                   ans+=left_max-height[left];
               left++;
           }
            else
            {
                       if(height[right]>=right_max)
                           right_max=height[right];
                       else
                           ans+=right_max-height[right];
                       right--;
            }
        }
         return ans;
    }
};
