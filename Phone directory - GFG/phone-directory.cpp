// { Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

 // } Driver Code Ends
// User function Template for C++
struct TrieNode{
    TrieNode *child[26];
    bool isEnd;
};
struct TrieNode *newNode()
{
    struct TrieNode *node=new TrieNode;
    for(int i=0;i<26;i++)
    node->child[i]=NULL;
    node->isEnd=false;
    return node;
};


class Solution{
public:
TrieNode *root=newNode();
void insert(TrieNode *curr,string contact)
{
    TrieNode *ptr=curr;
    for(int i=0;i<contact.length();i++)
    {
        int idx=contact[i]-'a';
        if(ptr->child[idx]==NULL)
        ptr->child[idx]=newNode();
        ptr=ptr->child[idx];
    }
    ptr->isEnd=true;
}
void printall(TrieNode *curr,vector<string>& temp,string prefix)
{
    if(curr->isEnd)
    {
        // cout<<prefix<<" ";
        temp.push_back(prefix);
    }
    for(char c='a';c<='z';c++)
    {
        TrieNode *node=curr->child[c-'a'];
        if(node!=NULL)
        printall(node,temp,prefix+c);
    }
}
void printoutput(vector<vector<string>>& res,string s)
{
    TrieNode *prev=root;
    string prefix="";
    int i;
    for(i=0;i<s.length();i++)
    {
        char lastChar=s[i];
        prefix+=lastChar;
        TrieNode *curr=prev->child[lastChar-'a'];
        if(curr==NULL)
        {
            string str="0";
            vector<string>v;
            v.push_back(str);
            res.push_back(v);
            break;
        }
        vector<string>temp;
        printall(curr,temp,prefix);
        sort(temp.begin(),temp.end());
        res.push_back(temp);
        temp.clear();
        prev=curr;
    }
    for(;i<s.length();i++)
    {
        string str="0";
            vector<string>v;
            v.push_back(str);
            res.push_back(v);
    }
}
    vector<vector<string>> displayContacts(int n, string contact[], string s)
    {
        // code here
        vector<vector<string>>res;
        
        for(int i=0;i<n;i++)
        insert(root,contact[i]);
        printoutput(res,s);
        return res;
      
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        string contact[n], s;
        for(int i = 0;i < n;i++)
            cin>>contact[i];
        cin>>s;
        
        Solution ob;
        vector<vector<string>> ans = ob.displayContacts(n, contact, s);
        for(int i = 0;i < s.size();i++){
            for(auto u: ans[i])
                cout<<u<<" ";
            cout<<"\n";
        }
    }
    return 0;
}  // } Driver Code Ends