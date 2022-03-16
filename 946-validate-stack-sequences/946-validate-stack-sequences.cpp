class Solution {
public:
    // bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
    //     int n1=pushed.size(),n2=popped.size();
    //     stack<int>s;
    //     unordered_set<int>st;
    //     int i=0,j=0;
    //     while(i<n1)
    //     {
    //         if(st.find(popped[j])!=st.end())
    //         {
    //             if(s.top()==popped[j])
    //                 s.pop();
    //             else
    //                 return false;
    //             j++;
    //         }
    //         else if(pushed[i]==popped[j])
    //         {
    //             i++,j++;
    //             continue;
    //         }
    //         else if(pushed[i]!=popped[j] && st.find(popped[j])==st.end())
    //         {
    //             s.push(pushed[i]);
    //             st.insert(pushed[i]);
    //             i++;
    //         }
    //     }
    //     while(j<n2)
    //     {
    //         if(s.empty())
    //             return false;
    //         if(s.top()!=popped[j])
    //             return false;
    //         s.pop();
    //         j++;
    //     }
    //     return true;
    // }
    
     bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n=pushed.size();
        stack<int>s;
         int j=0;
        for(int i=0;i<n;i++)
        {
            s.push(pushed[i]);
            while(!s.empty() && popped[j]==s.top() && j<n)
            {
                s.pop();
                j++;
            }
        }
         return j==n;
    }
};