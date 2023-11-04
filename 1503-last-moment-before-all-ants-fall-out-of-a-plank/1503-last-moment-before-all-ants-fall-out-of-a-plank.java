class Solution {
    public int getLastMoment(int n, int[] left, int[] right) {
        int n1=left.length,n2=right.length;
        int leftMax=Integer.MIN_VALUE,rightMin=Integer.MAX_VALUE;
        for(int i=0;i<n1;i++)
        {
            if(leftMax<left[i]){
                leftMax=left[i];
            }
        }
        for(int i=0;i<n2;i++){
            if(rightMin>right[i]){
                rightMin=right[i];
            }
        }
        return Math.max(leftMax,n-rightMin);
    }
}