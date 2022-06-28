// { Driver Code Starts
//

#include<bits/stdc++.h>
using namespace std;

struct Node
{
	int data;
	struct Node *left;
	struct Node *right;
	
	Node(int x){
	    data = x;
	    left = NULL;
	    right = NULL;
	}
};


void printPostOrder(Node *root)
{
	if(root==NULL)
		return;
	printPostOrder(root->left);
	printPostOrder(root->right);
	cout<<root->data<<" ";
}

 // } Driver Code Ends


/*Complete the code here.
Node is as follows:
struct Node
{
  int data;
  Node* left;
  Node* right;
};
*/
class Solution{
    public:
    Node *helper(int s,int e,int *preIdx,int in[],int pre[],int n)
    {
        if(s>e)
        return NULL;
        Node *root=new Node(pre[(*preIdx)++]);
        int idx=-1;
        for(int i=s;i<=e;i++)
        {
            if(in[i]==root->data)
            {
                idx=i;
                break;
            }
        }
        root->left=helper(s,idx-1,preIdx,in,pre,n);
        root->right=helper(idx+1,e,preIdx,in,pre,n);
        return root;
    }
    Node* buildTree(int in[],int pre[], int n)
    {
        // Code here
        int pIdx=0;
        return helper(0,n-1,&pIdx,in,pre,n);
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
		
		int inorder[n], preorder[n];
		for(int i=0; i<n; i++)
			cin>> inorder[i];
		for(int i=0; i<n; i++)
			cin>> preorder[i];
		Solution obj;
		Node *root = obj.buildTree(inorder, preorder, n);
		printPostOrder(root);
		cout<< endl;
	}
}
  // } Driver Code Ends