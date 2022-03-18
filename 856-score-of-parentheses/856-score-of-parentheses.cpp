class Solution {
public:
    // int scoreOfParentheses(string s) {
    //     stack<int> st;
    //     int score = 0;
    //     for(int i = 0; i < s.size(); i++){
    //         if(s[i] == '('){
    //             st.push(score);
    //             score = 0;
    //         }
    //         else {
    //             score = st.top() + max(2 * score, 1);
    //             st.pop();
    //         }
    //     }
    //     return score;
    // }
    
     int scoreOfParentheses(string s) {
         stack<int>st;
         int n=s.length();
         for(int i=0;i<n;i++)
         {
             if(s[i]=='(')
                 st.push(0);
             else if(st.top()==0) {
                 st.pop();
                 st.push(1);
             }
             else{
                 int sum=0;
                 while(st.top()!=0)
                 {
                     sum+=st.top();
                     st.pop();
                 }
                     st.pop();
                     st.push(sum*2);
             }
         }
         int ans=0;
         while(!st.empty())
         {
             ans+=st.top();
             st.pop();
         }
         return ans;
     }
};