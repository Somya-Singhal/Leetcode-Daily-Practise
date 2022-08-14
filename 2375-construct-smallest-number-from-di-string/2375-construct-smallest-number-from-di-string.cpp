class Solution {
public:
    string smallestNumber(string pattern) {
//         int n=pattern.length(),start=-1,end=-1;
//         string ans;

//         for(int i=1;i<=n+1;i++)
//         ans.push_back(i+48);

//         for(int i=0;i<n;i++)
//         {
//             if(pattern[i]=='D')
//             {
//                 if(start==-1)
//                 start=i;
//                 end=i;
//             }
//             else {
//                 if(start!=-1)
//                 reverse(ans.begin()+start,ans.begin()+end+2);
//                 start=-1;
//                 end=-1;
//             }
//         }

//         if(start!=-1)
//             reverse(ans.begin()+start,ans.begin()+end+2);

//         return ans;
        int n=pattern.size();
        string res="";
        stack<char>s;
        for(int i=0;i<=n;i++)
        {
            s.push('1'+i);
            if(i==n || pattern[i]=='I')
            {
                 while(!s.empty())
                 {
                    res+=s.top();
                    s.pop();
                 }
            }
        }
       
        return res;
    }
};