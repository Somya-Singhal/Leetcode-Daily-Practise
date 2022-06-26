// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    bool toporec(int x,stack<int>& s,vector<vector<int>>adj,vector<int>& vis,vector<bool>& recstack)
    {
        vis[x]=1;
        recstack[x]=true;
        for(auto i: adj[x])
        {
            if(!vis[i] && toporec(i,s,adj,vis,recstack))
            return true;
            else if(recstack[i])
            return true;
        }
        recstack[x]=false;
        s.push(x);
        return false;
    }
    void toposort(vector<vector<int>>adj,string &res)
    {
        int k=adj.size();
        vector<int>vis(k,0);
        vector<bool>recstack(k,false);
        stack<int>s;
        for(int i=0;i<k;i++)
        {
            if(!vis[i] && toporec(i,s,adj,vis,recstack))
            return;
        }
        while(!s.empty())
        {
            char ch=s.top()+'a';
            s.pop();
            res+=ch;
        }
    }
    string findOrder(string dict[], int N, int K) {
        //code here
        vector<vector<int>>adj(K,vector<int>());
        for(int i=1;i<N;i++)
        {
            string word1=dict[i-1];
            string word2=dict[i];
            int len1=word2.length(),len2=word1.length();
            int minlen=min(len1,len2);
            if(len1>len2 && word1.substr(0,minlen)==word2)
            return "";
            for(int j=0;j<minlen;j++)
            {
                if(word2[j]==word1[j])
                continue;
                else
                {
                    adj[word1[j]-'a'].push_back(word2[j]-'a');
                    break;
                }
            }
        }
        string res="";
        toposort(adj,res);
        // cout<<res<<" ";
        return res;
    }
};

// { Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}
  // } Driver Code Ends