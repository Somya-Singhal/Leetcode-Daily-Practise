class mycomp {
    public:
    bool operator()(string &s1,string &s2)
    {
        if(s1.size()!=s2.size())
            return s1.size()>s2.size();
        return s1>s2;
    }
};

class Solution {
public:
    string kthLargestNumber(vector<string>& nums, int k) {
        priority_queue<string,vector<string>,mycomp>pq;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            pq.push(nums[i]);
            if(pq.size()>k)
                pq.pop();
        }
        return pq.top();
    }
};