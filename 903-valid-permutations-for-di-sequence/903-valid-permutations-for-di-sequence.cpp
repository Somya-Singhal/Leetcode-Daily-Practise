class Solution {
public:
    int numPermsDISequence(string S) {
        int n = S.length(), M = (int)1e9 + 7;
        vector<int>dp(n + 1,1);
        for (int i = 1; i <= n; i++) {
            vector<int>temp(n+1,0);
            for (int j = 0; j <= i; j++) {
                temp[j] = j == 0 ? 0 : temp[j - 1];
                if (S[i - 1] == 'D') {
                    temp[j] += (dp[i - 1] - (j == 0 ? 0 : dp[j - 1])) % M;
                    if (temp[j] < 0) {
                        temp[j] += M;
                    }
                } else {
                    temp[j] += j == 0 ? 0 : dp[j - 1];
                }
                temp[j] %= M;
            }
            dp = temp;
        }
        return dp[n];
    }
};