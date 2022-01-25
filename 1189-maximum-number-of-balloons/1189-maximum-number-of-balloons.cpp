class Solution {
public:
    int maxNumberOfBalloons(string text) {
        vector<int>cnt(26,0);
        int n=text.length();
        int ans=INT_MAX;
        for(int i=0;i<n;i++)
        {
            if(text[i]=='b' || text[i]=='a' || text[i]=='l' || text[i]=='o' || text[i]=='n')
                cnt[text[i]-'a']++;
        }
        for(int i=0;i<26;i++)
        {
            if(i==('b'-'a') || i==('a'-'a') || i==('n'-'a'))
            {
                ans=min(ans,cnt[i]);
                // cout<<cnt[i]<<" ";
            }
             if( i==('l'-'a') || i==('o'-'a'))
             {
                 // cout<<cnt[i]<<" ";
                 if(cnt[i]%2==1)
                     cnt[i]--;
                  ans=min(ans,cnt[i]/2);
             }
        }
        return ans==INT_MAX?0:ans;
    }
};