class Solution {
public:
    int mod=1e9+7;
    
    int maximumProduct(vector<int>& nums, int k) {
        int n=nums.size();
        priority_queue<int,vector<int>,greater<int>>pq;
        long long sum=1;
        for(int i=0;i<n;i++){
            pq.push(nums[i]);
        }
        while(k>0){
            int t=pq.top();
            pq.pop();
            pq.push(t+1);
            k--;
        }
       while(!pq.empty()){
           sum*=pq.top();
           sum=sum%mod;
           pq.pop();
       }
        return sum%mod;
    }
};