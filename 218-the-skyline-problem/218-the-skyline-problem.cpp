class Solution {
public:
    // bool operator()(pair<int,int>& p1, pair<int,int>& p2)
    // {
    //     if(p1.first<p2.first)
    //         return p1<p2;
    //     return p1.second<=p2.second;
    // }
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<pair<int,int>>arr;
        int n=buildings.size();
        for(int i=0;i<n;i++)
        {
            arr.push_back({buildings[i][0],-buildings[i][2]});
            arr.push_back({buildings[i][1],buildings[i][2]});
        }
        sort(arr.begin(),arr.end());
        // for(int i=0;i<arr.size();i++)
        // {
        //     cout<<arr[i].first<<" "<<arr[i].second<<endl;
        // }
        vector<vector<int>>res;
        multiset<int>ml;
        int currht=0,pre=0;
        ml.insert({0});
        for(int i=0;i<arr.size();i++)
        {
            int x=arr[i].first;
            int ht=arr[i].second;
            if(ht<0)
                 ml.insert({-ht});
            else
                ml.erase(ml.find(ht));
            currht=*ml.rbegin();
            if(currht!=pre)
            {
                vector<int>temp;
                temp.push_back(x);
                temp.push_back(currht);
                res.push_back(temp);
                pre=currht;
            }
        }
        return res;
    }
};