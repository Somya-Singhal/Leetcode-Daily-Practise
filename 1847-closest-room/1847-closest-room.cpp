class Solution {
public:
    int searchClose(set<int>& s,int val)
    {
        auto c=s.lower_bound(val);
        int first=c!=begin(s)?*(prev(c)):-1;
        int second=c!=end(s)?*c:-1;
        return min(first,second)==-1?max(first,second):abs(first-val)<=abs(second-val)?first:second;
    }
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n=rooms.size(),q=queries.size();
        sort(rooms.begin(),rooms.end(),[](auto &a,auto &b){
            return a[1]>b[1];
        });
        for(int i=0;i<q;i++)
            queries[i].push_back(i);
        sort(queries.begin(),queries.end(),[](auto &a,auto &b){
            return a[1]>b[1];
        });
        set<int>s;
        vector<int>ans(q,-1);
        int j=0;
        for(int i=0;i<q;i++)
        {
            while(j<n && rooms[j][1]>=queries[i][1])
            {
                s.insert(rooms[j][0]);
                j++;
            }
            ans[queries[i][2]]=searchClose(s,queries[i][0]);
        }
        return ans;
    }
};