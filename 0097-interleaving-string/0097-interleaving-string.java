class Solution {
//     boolean solve(int i,int j,int k,String s1, String s2, String s3,HashMap<String, Boolean>cache){
//         if(i==s1.length() && j==s2.length() && k==s3.length())
//             return true;
        
//         String str=Integer.toString(i)+" "+Integer.toString(j)+" "+Integer.toString(k);
//         if(cache.containsKey(str))
//             return cache.get(str);
//         if(i<s1.length() && j<s2.length()){
//         if(s3.charAt(k)==s1.charAt(i) && s3.charAt(k)==s2.charAt(j)){
//             boolean val = solve(i+1,j,k+1,s1,s2,s3,cache) || solve(i,j+1,k+1,s1,s2,s3,cache);
//             cache.put(str,val);    
//             return val;
//         }
//         else if(s1.charAt(i)==s3.charAt(k)){
//             boolean val=solve(i+1,j,k+1,s1,s2,s3,cache);
//             cache.put(str,val);
//             return val;
//         }
//         else if(s3.charAt(k)==s2.charAt(j)){
//             boolean val=solve(i,j+1,k+1,s1,s2,s3,cache);
//             cache.put(str,val);
//             return val;
//         }
//         }
//         else if(i<s1.length() && s1.charAt(i)==s3.charAt(k)){
//             boolean val=solve(i+1,j,k+1,s1,s2,s3,cache);
//             cache.put(str,val);
//             return val;
//         }
            
//         else if(j<s2.length() && s2.charAt(j)==s3.charAt(k)){
//             boolean val=solve(i,j+1,k+1,s1,s2,s3,cache);
//             cache.put(str,val);
//             return val;
//         }    
//         cache.put(str,false);
//         return false;
//     }
    public boolean isInterleave(String s1, String s2, String s3) {
        int n=s1.length();
        int m=s2.length();
        int t=s3.length();
        if((n+m)!=t)
            return false;
        // HashMap<String, Boolean>cache=new HashMap<>();
        // return solve(0,0,0,s1,s2,s3,cache);
        boolean[][] dp=new boolean[n+1][m+1];
        for(int i=0;i<=n;i++){
            for(int j=0;j<=m;j++){
                if(i==0 && j==0)
                    dp[i][j]=true;
                else if(i==0)
                    dp[i][j]=dp[i][j-1]&&(s2.charAt(j-1)==s3.charAt(i+j-1));
                else if(j==0)
                    dp[i][j]=dp[i-1][j]&&s1.charAt(i-1)==s3.charAt(i+j-1);
                else
                    dp[i][j]=((dp[i][j-1]&&s2.charAt(j-1)==s3.charAt(i+j-1)) || (dp[i-1][j]&&s1.charAt(i-1)==s3.charAt(i+j-1)));
                
            }
        }
        return dp[n][m];
    }
}