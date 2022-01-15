class Solution {
public:
    //state machine
   
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int>s(n),s1(n),s2(n);
        s[0]=0;
        s1[0]=-prices[0];
        s2[0]=INT_MIN;
        for(int i=1;i<n;i++)
        {
            s[i]=max(s[i-1],s2[i-1]);
            s1[i]=max(s1[i-1],s[i-1]-prices[i]);
            s2[i]=s1[i-1]+prices[i];
        }
       return max(s[n-1],s2[n-1]);
    }
};