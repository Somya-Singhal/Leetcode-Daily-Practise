class Solution {
public:
    int titleToNumber(string columnTitle) {
        int n=columnTitle.length();
        int ans=0,power=pow(26,n-1);
        for(int i=0;i<n;i++)
        {
            ans+=power*(columnTitle[i]-'A'+1);
            power=power/26;
        }
        return ans;
    }
};