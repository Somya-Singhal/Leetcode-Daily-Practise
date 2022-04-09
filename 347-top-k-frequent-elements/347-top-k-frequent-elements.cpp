class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        priority_queue<pair<int,int>,vector<pair<int,int>>>pq;
        unordered_map<int,int>vis;
        vector<int>ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            vis[nums[i]]++;
        }
        for(auto x: vis){
            pq.push({x.second,x.first});
        }
        while(!pq.empty() && ans.size()<k){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};