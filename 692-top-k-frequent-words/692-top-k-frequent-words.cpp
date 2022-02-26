class Solution {
public:
    
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string,int>wordsmap;
        vector<string>res;
        int n=words.size();
        for(int i=0;i<n;i++)
        {
            wordsmap[words[i]]++;
        }
        auto Compare = [&](const pair<int,string>& p1, const pair<int,string>& p2) {
            if(p1.first==p2.first)
                return p1.second<p2.second;
            return p1.first>p2.first;
        };
        priority_queue<pair<int,string>,vector<pair<int,string>>,decltype(Compare)>pq(Compare);
        for(auto &x: wordsmap)
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
        reverse(res.begin(),res.end());
        return res;
    }
};