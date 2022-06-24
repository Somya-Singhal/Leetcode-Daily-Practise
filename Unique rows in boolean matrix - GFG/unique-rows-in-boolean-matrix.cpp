// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;
#define MAX 1000

vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col);

int main()
{
    int T;
    cin>>T;
    while(T--)
    {
    	int n,m;
    	cin>>n>>m;
    	int a[MAX][MAX];
    	for(int i=0;i<n;i++)
    	for(int j=0;j<m;j++)
    	cin>>a[i][j];
    	vector<vector<int>> vec = uniqueRow(a,n,m);
    	for(int i = 0;i<vec.size();i++){
    	    for(int x : vec[i]){
    	        cout<<x<<" ";
    	    }
    	    cout<<"$";
    	}
    	cout<<endl;
    }
}
// } Driver Code Ends


/*You are required to complete this function*/
struct TrieNode{
    struct TrieNode *children[2];
    bool isEnd;
};
struct TrieNode *getNode(void)
{
    struct TrieNode *ptr=new TrieNode;
    ptr->isEnd=false;
    for(int i=0;i<2;i++)
    ptr->children[i]=NULL;
    return ptr;
};
bool insert(struct TrieNode **t,int M[MAX][MAX],int r,int c,int COL)
{
   if(*t==NULL)
   *t=getNode();
   if(c<COL)
   return insert(&((*t)->children[M[r][c]]),M,r,c+1,COL);
   else{
       if(!((*t)->isEnd))
       return (*t)->isEnd=1;
       return 0;
   }
}
void printNode(int M[MAX][MAX],int row,int col,vector<vector<int>>& res)
{
    vector<int>v;
    for(int i=0;i<col;i++)
    v.push_back(M[row][i]);
    res.push_back(v);
}
vector<vector<int>> uniqueRow(int M[MAX][MAX],int row,int col)
{
//Your code here
vector<vector<int>>res;
struct TrieNode *root=NULL;
for(int i=0;i<row;i++)
{
    
    for(int j=0;j<col;j++)
    {
        if(insert(&root,M,i,0,col))
        printNode(M,i,col,res);
    }
}

return res;

}