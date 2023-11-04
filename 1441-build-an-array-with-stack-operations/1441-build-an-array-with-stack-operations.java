class Solution {
    public List<String> buildArray(int[] target, int n) {
        int count=1,i=0;
        Stack<Integer>st = new Stack<>();
        List<String>ans=new ArrayList<>();
        int sz=target.length;
        while(i<sz){
            ans.add("Push");
            st.push(count);
            count+=1;
            if(st.peek()==target[i]){
                i+=1;
            } else {
                ans.add("Pop");
                st.pop();
            }
        }
        return ans;
    }
}