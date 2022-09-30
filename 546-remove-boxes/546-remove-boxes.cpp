class Solution {
public:
    int dp[101][101][101];
    int solve(int l,int r,int count,vector<int>& boxes)
    {
        if(l>r)
            return 0;
        if(dp[l][r][count]!=0)
            return dp[l][r][count];
        int l1=l,count1=count;
        while(l+1<=r && boxes[l]==boxes[l+1])
        {
            count+=1;
            l+=1;
        }
       int ans=(count+1)*(count+1)+solve(l+1,r,0,boxes);
        for(int k=l+1;k<=r;k++)
        {
            if(boxes[k]==boxes[l])
                ans=max(ans,solve(k,r,count+1,boxes)+solve(l+1,k-1,0,boxes));
        }
        dp[l1][r][count1]=ans;   
        return dp[l1][r][count1];
    }
    int removeBoxes(vector<int>& boxes) {
        int n=boxes.size();
        memset(dp,0,sizeof(dp));
        return solve(0,n-1,0,boxes);
    }
};