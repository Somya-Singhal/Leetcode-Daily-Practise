class Solution {
public:
    int minSetSize(vector<int>& arr) {
        // map<int,int>mp;
        // priority_queue<pair<int,int>>pq;
        // int n=arr.size();
        // for(int i=0;i<n;i++)
        // {
        //     mp[arr[i]]++;
        // }
        // for(auto x: mp)
        // {
        //     pq.push({x.second,x.first});
        // }
        // int sum=0;
        // for(auto x: mp)
        //     sum+=x.second;
        // int target=sum/2,count=0;
        // while(sum>target)
        // {
        //     sum-=pq.top().first;
        //     pq.pop();
        //     count+=1;
        // }
        // return count;
        
        unordered_map<int,int>mp;
        int n=arr.size();
        for(int i=0;i<n;i++)
        {
            mp[arr[i]]++;
        }
        vector<int>freq;
        int count=0;
        for(auto x: mp)
        {
            freq.push_back(x.second);
        }
        sort(freq.begin(),freq.end(),greater<int>());
        int i=0,target=n/2; 
        while(n>target)
        {
            n-=freq[i++];
            count+=1;
        }
        return count;
    }
};