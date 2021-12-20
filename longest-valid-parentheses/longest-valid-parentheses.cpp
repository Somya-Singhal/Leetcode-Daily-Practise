class Solution {
public:
    //time->O(n)
    // int longestValidParentheses(string s) {
    //     int n=s.length();
    //     int len=0,open=0,close=0;
    //     for(int i=0;i<n;i++)
    //     {
    //             if(s[i]=='(')
    //                 open++;
    //             else
    //                 close++;
    //             if(open==close)
    //              len=max(len,2*open); 
    //             else if(close>open)
    //                 open=0,close=0;
    //     }
    //     open=0,close=0;
    //     for(int i=n-1;i>=0;i--)
    //     {
    //             if(s[i]=='(')
    //                 open++;
    //             else
    //                 close++;
    //             if(open==close)
    //              len=max(len,2*open); 
    //             else if(open>close)
    //                 open=0,close=0;
    //     }
    //     return len;
    // }
    
    //time->O(n)  Space->O(n)
    // int longestValidParentheses(string s) {
    //     int n=s.length();
    //     stack<int>st;
    //     st.push(-1);
    //     int len=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(s[i]=='(')
    //             st.push(i);
    //         else
    //         {
    //             st.pop();
    //             if(st.empty())
    //                 st.push(i);
    //             else
    //             {
    //                int top=i-st.top();
    //                 len=max(len,top);
    //             }
    //         }
    //     }
    //     return len;
    // }
    
    //time->O(n),Space->O(n)
    // int longestValidParentheses(string s) {
    //     int n=s.length();
    //     int dp[n];
    //     stack<int>st;
    //     st.push(-1);
    //     int len=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         if(s[i]=='(')
    //             st.push(i);
    //         else
    //         {
    //             st.pop();
    //             if(st.empty())
    //                 st.push(i);
    //             else
    //             {
    //                int top=i-st.top();
    //                 len=max(len,top);
    //             }
    //         }
    //     }
    //     return len;
    // }
    
    //Brute force->O(n*n*n),Space->O(n)
    // bool isvalid(int i,int j,string s)
    // {
    //     stack<char>st;
    //     for(int k=i;k<j;k++)
    //     {
    //         if(st.empty() && s[k]==')')
    //             return false;
    //         else if(s[k]=='(')
    //             st.push('(');
    //         else
    //             st.pop();
    //     }
    //     return st.empty();
    // }
    // int longestValidParentheses(string s) {
    //     int n=s.length();
    //     int len=0;
    //     for(int i=0;i<n;i++)
    //     {
    //         for(int j=i+2;j<=n;j+=2)
    //         {
    //             if(isvalid(i,j,s))
    //             {
    //                 len=max(len,j-i);
    //             }
    //         }
    //     }
    //     return len;
    // }
    
    int longestValidParentheses(string s) {
        int n=s.length();
        int len=0;
        vector<int>dp(n,0);
        for(int i=1;i<n;i++)
        {
           if(s[i]==')')
           {
               if(s[i-1]=='(')
                   dp[i]=(i>=2?dp[i-2]:0)+2;
               else
               {
                   if(i-dp[i-1]>0 && s[i-dp[i-1]-1]=='(')
                       dp[i]=dp[i-1]+((i-dp[i-1]-2)>=0?dp[i-dp[i-1]-2]:0)+2;
               }
           }
            len=max(len,dp[i]);
        }
        return len;
    }
};
