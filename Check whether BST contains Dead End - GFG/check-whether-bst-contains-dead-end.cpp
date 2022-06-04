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
void inorderbst(Node* root,unordered_set<int> &s1,vector<int> &v){
    if(root==NULL)
    return;
    inorderbst(root->left,s1,v);
    s1.insert(root->data);
    if(root->left==NULL && root->right==NULL)
    v.push_back(root->data);
    inorderbst(root->right,s1,v);
}
bool isDeadEnd(Node *root)
{
    //Your code here
    // stack<Node*>s;
    // Node* curr=root,*pp=NULL,*np=NULL;
    // while(curr!=NULL || !s.empty())
    // {
    //     while(curr!=NULL)
    //     {
    //         s.push(curr);
    //         pp=curr;
    //         curr=curr->left;
    //     }
    //     curr=s.top();
    //     s.pop();
    //     if(np!=NULL && np->data+1==curr->data)
    //     {
    //         if(pp!=NULL && )
    //     }
    // }
    // return true;
    
    unordered_set<int>s1;
    vector<int>v;
    inorderbst(root,s1,v);
    for(auto x: v)
    {
        if(x==1 && s1.find(2)!=s1.end())
        return true;
        else if(s1.find(x-1)!=s1.end() && s1.find(x+1)!=s1.end())
        return true;
    }
    return false;
}