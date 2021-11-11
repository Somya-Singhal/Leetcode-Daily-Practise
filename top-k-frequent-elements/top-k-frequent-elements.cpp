class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>res;
        unordered_map<int,int>m;
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        for(int i=0;i<n;i++)
        {
                m[nums[i]]++;
        }
        for(auto x: m)
        {
            pq.push(make_pair(x.second,x.first));
            if(pq.size()>k)
            pq.pop();
        }
        while(!pq.empty())
        {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};