class Solution {
    public int buyChoco(int[] prices, int money) {
        int n = prices.length;
        int smallest=Integer.MAX_VALUE, second_smallest=Integer.MAX_VALUE;
        int ans=money;
        for(int i=0;i<n;i++){
            if(prices[i]<smallest){
                second_smallest=smallest;
                smallest=prices[i];
            } else if(prices[i]<second_smallest){
                second_smallest=prices[i];
            }
        }
        System.out.println(smallest + " " + second_smallest);
        return ((money-(smallest+second_smallest))>=0)?(money-(smallest+second_smallest)): money;
    }
}