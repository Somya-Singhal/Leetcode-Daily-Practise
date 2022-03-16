class Solution {
public:
//     string getHappyString(int n, int k) {
//         queue<string>q;
//         q.push("a");
//         q.push("b");
//         q.push("c");
//         while(!q.empty())
//         {
//             int len=q.size();
//             for(int i=0;i<len;i++)
//             {
//                 string str=q.front();
//                 int s=str.length();
//                 q.pop();
//                 if(s>n)
//                     return "";
//                 if(s==n)
//                     k--;
//                 if(k==0)
//                     return str;
                
//                 if(str[s-1]=='a')
//                 {
//                     q.push(str+'b');
//                     q.push(str+'c');
//                 }
//                 else if(str[s-1]=='b')
//                 {
//                     q.push(str+'a');
//                     q.push(str+'c');
//                 }
//                 else
//                 {
//                     q.push(str+'a');
//                     q.push(str+'b');
//                 }
//             }
//         }
//         return "";
//     }
    
    vector<string>res;
    void solve(string ans,int n,int k)
    {
        if(res.size()==k)
            return;
        if(ans.length()>n)
            return;
        if(ans.length()==n)
            res.push_back(ans);
        for(char ch='a';ch<='c';ch++)
        {
            if(ans=="" || (ans.size()>0 && ch!=ans[ans.length()-1]))
                solve(ans+ch,n,k);
        }
    }
    string getHappyString(int n, int k) {
        solve("",n,k);
        return res.size()==k?res[k-1]:"";
    }
};