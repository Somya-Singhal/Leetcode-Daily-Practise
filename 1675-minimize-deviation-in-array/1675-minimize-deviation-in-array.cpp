class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        // priority_queue<int>pq;
        // int n=nums.size();
        // int currmin=INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]%2)
        //     {
        //         pq.push(nums[i]*2);
        //         currmin=min(currmin,nums[i]*2);
        //     }
        //     else
        //     {
        //         pq.push(nums[i]);
        //         currmin=min(currmin,nums[i]);
        //     }
        // }
        // int currdev=INT_MAX;
        // while(pq.top()%2==0)
        // {
        //     int t=pq.top();
        //     pq.pop();
        //     currdev=min(currdev,t-currmin);
        //     pq.push(t/2);
        //     currmin=min(currmin,t/2);
        // }
        // return currdev=min(currdev,pq.top()-currmin);
        
        // multiset<int>s;
        // int n=nums.size();
        // int currmin=INT_MAX;
        // for(int i=0;i<n;i++)
        // {
        //     if(nums[i]%2)
        //     {
        //         s.insert(nums[i]*2);
        //         currmin=min(currmin,nums[i]*2);
        //     }
        //     else
        //     {
        //         s.insert(nums[i]);
        //         currmin=min(currmin,nums[i]);
        //     }
        // }
        // int currdev=INT_MAX;
        // while(*s.rbegin()%2==0)
        // {
        //     int t=*s.rbegin();
        //     s.erase(*s.rbegin());
        //     currdev=min(currdev,t-*s.begin());
        //     s.insert(t/2);
        // }
        // return currdev=min(currdev,*s.rbegin()-*s.begin());
        
       
        int res=INT_MAX,min_n=INT_MAX;
        for(int i=0;i<nums.size();i++)
        {
            nums[i]=nums[i]%2?nums[i]*2:nums[i];
            min_n=min(min_n,nums[i]);
        }
        make_heap(begin(nums),end(nums));
        while(nums[0]%2==0)
        {
            res=min(res,nums[0]-min_n);
            min_n=min(min_n,nums[0]/2);
            pop_heap(begin(nums),end(nums));
            nums.back()/=2;
            push_heap(begin(nums),end(nums));
        }
        return min(res,nums[0]-min_n);
    }
};