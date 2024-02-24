class Solution {
    // public int solve(int i,int profit,int k,int[] prices,boolean bought,HashMap<String,Integer>cache){
    //     if(i==prices.length){
    //         return profit;
    //     }
    //     String str=Integer.toString(i)+" "+Integer.toString(profit)+" "+Integer.toString(k)+" "+Boolean.toString(bought);
    //     if(cache.containsKey(str)){
    //         return cache.get(str);
    //     }
    //     int currprofit=0;
    //     if(bought){
    //         currprofit=Integer.max(solve(i+1,profit+prices[i],k,prices,false,cache),solve(i+1,profit,k,prices,true,cache));
    //         cache.put(str,currprofit);
    //         return currprofit;
    //     } else if(k>0){
    //         currprofit=Integer.min(solve(i+1,profit-prices[i],k-1,prices,true,cache),solve(i+1,profit,k,prices,false,cache));
    //         cache.put(str,currprofit);
    //         return currprofit;
    //     }
    //     currprofit=solve(i+1,profit,k,prices,false,cache);
    //     cache.put(str,currprofit);
    //     return currprofit;
    // }
    public int maxProfit(int k, int[] prices) {
        // HashMap<String,Integer>cache=new HashMap<>();
        int n=prices.length;
        int[][] dp=new int[k+1][2];
        for(int i=0;i<=k;i++)
        {
            dp[i][0]=Integer.MIN_VALUE;
            // dp[i][0][1]=0;
        }
        for(int j=0;j<n;j++){
        for(int i=1;i<=k;i++){
            
                dp[i][0]=Integer.max(-prices[j]+dp[i-1][1],dp[i][0]);
                dp[i][1]=Integer.max(prices[j]+dp[i][0],dp[i][1]);
                
            }
        }
        return dp[k][1];
        // return solve(0,0,k,prices,false,cache);
    }
}