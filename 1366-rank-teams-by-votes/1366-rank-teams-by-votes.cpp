class Solution {
public:
    
    string rankTeams(vector<string>& votes) {
        int len=votes[0].length();
        int n=votes.size();
        vector<vector<int>>count(26,vector<int>(len,0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<len;j++)
            {
                count[votes[i][j]-'A'][j]+=1;
            }
        }
        string ans(votes[0]);
        
        sort(ans.begin(),ans.end(), [&](const char &c1,const char &c2) {
            for(int i=0;i<len;i++)
            {
                if(count[c1-'A'][i]!=count[c2-'A'][i])
                    return count[c2-'A'][i]<count[c1-'A'][i];
            }
            return c1<c2;
        });
        
        
        return ans;
    }
};