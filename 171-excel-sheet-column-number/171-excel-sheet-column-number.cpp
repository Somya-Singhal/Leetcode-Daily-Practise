class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=pow(26,n-i-1)*(columnTitle[i]-'A'+1);
        }
        return ans;
    }
};