// { Driver Code Starts
//Initial Template for C++
#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;


 // } Driver Code Ends
//User function Template for C++
struct NextNode{
    struct NextNode *nxt;
    int idx;
};
struct TrieNode{
    struct TrieNode *children[256];
    struct NextNode *head;
    bool isEnd;
};
struct TrieNode *newNode() {
    struct TrieNode *t=new TrieNode;
    t->isEnd=false;
    t->head=NULL;
    for(int i=0;i<256;i++)
    t->children[i]=NULL;
    return t;
};
int compare(const void* a, const void* b)
{  return *(char*)a - *(char*)b; }
struct NextNode *Node(int idx)
{
    struct NextNode *n=new NextNode;
    n->idx=idx;
    n->nxt=NULL;
    return n;
};
void insert(struct TrieNode **root,char *word,int idx)
{
    if(*root==NULL)
    *root=newNode();
    if(*word!='\0')
    {
        insert(&((*root)->children[tolower(*word)-'a']),word+1,idx);
    }
    else{
        if((*root)->isEnd)
        {
            NextNode *ptr=(*root)->head;
            while(ptr->nxt)
            ptr=ptr->nxt;
            ptr->nxt=Node(idx);
        }
        else
        {
            (*root)->isEnd=1;
            (*root)->head=Node(idx);
        }
    }
};
void printNode(struct TrieNode *root,vector<string>& string_list,vector<vector<string>>& res)
{
    if(root==NULL)
    return;
    vector<string>v;
    if(root->isEnd)
    {
        NextNode *ptr=root->head;
        while(ptr!=NULL)
        {
            v.push_back(string_list[ptr->idx]);
            
            ptr=ptr->nxt;
        }
        res.push_back(v);
    }
    for(int i=0;i<256;i++)
    printNode(root->children[i],string_list,res);
}
class Solution{
  public:
    vector<vector<string> > Anagrams(vector<string>& string_list) {
        //code here
        vector<vector<string>>res;
        struct TrieNode *root=NULL;
        int n=string_list.size();
        for(int i=0;i<n;i++)
        {
            
            int len=string_list[i].length();
            char *word=new char[len+1];
            strcpy(word,string_list[i].c_str());
            qsort( (void*)word, strlen(word), sizeof(char), compare );
        
            insert(&root,word,i);
        }
        printNode(root,string_list,res);
        return res;
    }
};

// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<string> string_list(n);
        for (int i = 0; i < n; ++i)
            cin>>string_list[i]; 
        Solution ob;
        vector<vector<string> > result = ob.Anagrams(string_list);
        sort(result.begin(),result.end());
        for (int i = 0; i < result.size(); i++)
        {
            for(int j=0; j < result[i].size(); j++)
            {
                cout<<result[i][j]<<" ";
            }
            cout<<"\n";
        }
    }

    return 0;
}
  // } Driver Code Ends