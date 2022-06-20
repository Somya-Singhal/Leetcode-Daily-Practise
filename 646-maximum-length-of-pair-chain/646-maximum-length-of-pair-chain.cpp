class Solution {
public:
    static bool compare(vector<int>v1,vector<int>v2)
    {
        if(v1[1]==v2[1])
            return v1[0]<v2[0];
        return v1[1]<v2[1];
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end(),compare);
        int n=pairs.size();
        int curr=INT_MIN,ans=0;
        for(int i=0;i<n;i++)
        {
            if(curr<pairs[i][0])
            {
                curr=pairs[i][1];
                ans++;
            }
        }
        return ans;
    }
};