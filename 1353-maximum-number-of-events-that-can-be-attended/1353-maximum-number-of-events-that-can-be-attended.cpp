class Solution {
public:
   
    int maxEvents(vector<vector<int>>& events) {
        int n=events.size();
        sort(events.begin(),events.end());
       
        int end=1;
        for(int i=0;i<n;i++)
            end=max(end,events[i][1]);
        int count=0,i=0;
        priority_queue<int,vector<int>,greater<int>>pq;
        for(int day=1;day<=end;day++)
        {
           while(!pq.empty() && pq.top()<day)
            pq.pop();
           while(i<n && events[i][0]<=day)
               pq.push(events[i++][1]);
           if(!pq.empty())
           {
               pq.pop();
               count+=1;
           }
        }
        return count;
    }
};