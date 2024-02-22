class Solution {
    public int findLongestChain(int[][] pairs) {
        // int n=pairs.length;
        // int longestChainLength=1;
        // int[] dp = new int[n];
        // dp[0]=1;
        // Arrays.sort(pairs, new Comparator<int[]>() {
        //     @Override
        //     public int compare(final int[] arr1, final int[] arr2){
        //         if(arr1[0]>arr2[0])
        //             return 1;
        //         return -1;
        //     }
        // });
        // for(int[] ele: pairs){
        //     System.out.println(ele[0] + " " + ele[1]);
        // }
//         for(int i=1;i<n;i++){
//             dp[i]=1;
//             for(int j=0;j<i;j++){
//             if(pairs[i][0]>pairs[j][1]){
//                 dp[i]=Math.max(dp[i],dp[j]+1);
//             }
//           }
//           longestChainLength = Math.max(longestChainLength,dp[i]);
//         }
        
//         return longestChainLength;
        int longestChainLength=1;
        Arrays.sort(pairs,new Comparator<int[]>() {
            @Override
            public int compare(final int[] p1, final int[] p2){
                if(p1[1]>p2[1])
                    return 1;
                return -1;
            }
        });
        int curr=pairs[0][1];
        for(int i=1;i<pairs.length;i++){
            if(pairs[i][0]>curr){
                longestChainLength+=1;
                curr=pairs[i][1];
            }
        }
        return longestChainLength;
    }
}