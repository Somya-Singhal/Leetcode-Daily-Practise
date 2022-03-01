class Solution {
public:
    // int minHeightShelves(vector<vector<int>>& books, int shelfWidth) {
    //     int n=books.size();
    //     vector<int>dp(n+1,0);
    //     for(int i=1;i<=n;i++)
    //     {
    //         int currMaxHeight=books[i-1][1];
    //         int width=books[i-1][0];
    //         dp[i]=dp[i-1]+currMaxHeight;
    //         for(int j=i-1;j>0 && width+books[j-1][0]<=shelfWidth;j--)
    //         {
    //             currMaxHeight=max(currMaxHeight,books[j-1][1]);
    //             width+=books[j-1][0];
    //             dp[i]=min(dp[i],dp[j-1]+currMaxHeight);
    //         }
    //     }
    //     return dp[n];
    // }
    
     int dp[1001][1001]={};
     int minHeightShelves(vector<vector<int>>& books, int shelfWidth,int idx=0,int wt=0,int maxht=0) {
        if(idx>=books.size())
            return maxht;
        if(dp[idx][wt]!=0)
            return dp[idx][wt];
        return dp[idx][wt]=min(maxht+minHeightShelves(books,shelfWidth,idx+1,books[idx][0],books[idx][1]),wt+books[idx][0]>shelfWidth?INT_MAX:minHeightShelves(books,shelfWidth,idx+1,wt+books[idx][0],max(maxht,books[idx][1])));
    }
};