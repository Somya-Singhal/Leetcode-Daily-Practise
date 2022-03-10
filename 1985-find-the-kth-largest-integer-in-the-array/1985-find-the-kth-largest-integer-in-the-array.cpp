class mymincomp {
    public:
    bool operator()(string &s1,string &s2)
    {
        if(s1.size()!=s2.size())
            return s1.size()>s2.size();
        return s1>s2;
    }
};

// class mymaxcomp {
//     public:
//     bool operator()(string &s1,string &s2)
//     {
//         if(s1.size()!=s2.size())
//             return s1.size()<s2.size();
//         return s1<s2;
//     }
// };
class Solution {
public:
    //min-heap->O(nlogk*m)
    // string kthLargestNumber(vector<string>& nums, int k) {
    //     priority_queue<string,vector<string>,mymincomp>pq;
    //     int n=nums.size();
    //     for(int i=0;i<n;i++)
    //     {
    //         pq.push(nums[i]);
    //         if(pq.size()>k)
    //             pq.pop();
    //     }
    //     return pq.top();
    // }
    
    //max-heap->O((n+klogn)*m)
    // string kthLargestNumber(vector<string>& nums, int k) {
    //     make_heap(nums.begin(),nums.end(),mymaxcomp());
    //     while(k-->1)
    //     {
    //         pop_heap(nums.begin(),nums.end(),mycomp());
    //         nums.pop_back();
    //     }
    //     return nums.front();
    // }
    
    //time->O(n*m)
    string kthLargestNumber(vector<string>& nums, int k) {
        nth_element(nums.begin(),nums.begin()+k-1,nums.end(),mymincomp());
        return nums[k-1];
    }
    
};