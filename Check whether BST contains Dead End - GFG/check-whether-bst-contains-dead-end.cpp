// { Driver Code Starts
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


void insert(Node ** tree, int val)
{
    Node *temp = NULL;
    if(!(*tree))
    {
        temp = new Node(val);
        *tree = temp;
        return;
    }

    if(val < (*tree)->data)
    {
        insert(&(*tree)->left, val);
    }
    else if(val > (*tree)->data)
    {
        insert(&(*tree)->right, val);
    }

}




int getCountOfNode(Node *root, int l, int h)
{

    if (!root) return 0;


    if (root->data == h && root->data == l)
        return 1;

    if (root->data <= h && root->data >= l)
         return 1 + getCountOfNode(root->left, l, h) +
                    getCountOfNode(root->right, l, h);

    else if (root->data < l)
         return getCountOfNode(root->right, l, h);


    else return getCountOfNode(root->left, l, h);
}


bool isDeadEnd(Node *root);
int main()
{
    int T;
    cin>>T;
    while(T--)
    {
        Node *root;
        Node *tmp;
    //int i;

        root = NULL;

        int N;
        cin>>N;
        for(int i=0;i<N;i++)
        {
            int k;
            cin>>k;
            insert(&root, k);

        }

        
     cout<<isDeadEnd(root);
     cout<<endl;
    }
}

// } Driver Code Ends


/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

/*You are required to complete below method */
// void inorderbst(Node* root,unordered_set<int> &s1,vector<int> &v){
//     if(root==NULL)
//     return;
//     inorderbst(root->left,s1,v);
//     s1.insert(root->data);
//     if(root->left==NULL && root->right==NULL)
//     v.push_back(root->data);
//     inorderbst(root->right,s1,v);
// }
bool solve(Node* root,int min_val,int max_val)
{
    if(root==NULL)
    return false;
    if(min_val==max_val)
    return true;
    return solve(root->left,min_val,root->data-1) || solve(root->right,root->data+1,max_val);
}
bool isDeadEnd(Node *root)
{
    
    // unordered_set<int>s1;
    // vector<int>v;
    // inorderbst(root,s1,v);
    // for(auto x: v)
    // {
    //     if(x==1 && s1.find(2)!=s1.end())
    //     return true;
    //     else if(s1.find(x-1)!=s1.end() && s1.find(x+1)!=s1.end())
    //     return true;
    // }
    // return false;
    return solve(root,1,INT_MAX);
    
}