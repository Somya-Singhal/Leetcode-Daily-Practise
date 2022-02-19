class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        priority_queue<int>pq;
        int n=nums.size();
        int currmin=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(nums[i]%2)
            {
                pq.push(nums[i]*2);
                currmin=min(currmin,nums[i]*2);
            }
            else
            {
                pq.push(nums[i]);
                currmin=min(currmin,nums[i]);
            }
        }
        int currdev=INT_MAX;
        while(pq.top()%2==0)
        {
            int t=pq.top();
            pq.pop();
            currdev=min(currdev,t-currmin);
            pq.push(t/2);
            currmin=min(currmin,t/2);
        }
        return currdev=min(currdev,pq.top()-currmin);
    }
};