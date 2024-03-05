class Solution {
    public int largestRectangleArea(int[] heights) {
        int n=heights.length;
        Stack<Integer>st=new Stack<>();
        st.push(0);
        int[] leftmin = new int[n];
        int[] rightmin = new int[n];
        int ans=Integer.MIN_VALUE;
        leftmin[0]=-1;
        for(int i=1;i<n;i++){
            while(!st.empty() && heights[st.peek()]>=heights[i])
                st.pop();
            leftmin[i]=(!st.empty() ? st.peek():-1);
            st.push(i);
        }
        st.clear();
        st.push(n-1);
        rightmin[n-1]=n;
        for(int i=n-2;i>=0;i--){
            while(!st.empty() && heights[st.peek()]>=heights[i])
                st.pop();
            rightmin[i]=(!st.empty() ? st.peek():n);
            st.push(i);
        }
        
        for(int i=0;i<n;i++){
            ans=Math.max(ans,(rightmin[i]-leftmin[i]-1)*heights[i]);
        }
        return ans;
    }
}