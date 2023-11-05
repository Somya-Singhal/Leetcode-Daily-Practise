class Solution {
    public int getWinner(int[] arr, int k) {
        int j=1,count=0,currWinner=arr[0],prevWinner=Integer.MIN_VALUE;
        int n=arr.length;
        while(count<k){
            if(arr[j]>arr[0])
            {
                arr[0]=arr[j];
            }
            currWinner = Math.max(arr[0],arr[j]);
            if(prevWinner==Integer.MIN_VALUE || prevWinner==currWinner)
                count+=1;
            else {
                count=1;
            }
            if(count==k)
                break;
            j+=1;
            if(j==n) j=1;
            prevWinner=currWinner;
        }
        return currWinner;
    }
}