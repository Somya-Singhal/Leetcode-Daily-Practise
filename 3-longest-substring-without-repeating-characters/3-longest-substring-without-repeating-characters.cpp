class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ans=0;
        int n=s.length();
        unordered_map<char,int>lastInd;
        int newstart=0;
        for(int i=0;i<n;i++)
        {
            if(lastInd.find(s[i])!=lastInd.end())
            {
                ans=max(ans,i-max(lastInd[s[i]],newstart-1));
                newstart=max(newstart-1,lastInd[s[i]])+1;
            }
            else
                ans=max(ans,i-newstart+1);
            lastInd[s[i]]=i;
        }
        return ans;
    }
};