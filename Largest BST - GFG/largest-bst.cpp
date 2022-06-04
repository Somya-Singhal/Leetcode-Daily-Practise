// { Driver Code Starts
//Initial Template for C++


#include <bits/stdc++.h>
using namespace std;
#define MAX_HEIGHT 100000

// Tree Node
struct Node {
    int data;
    Node* left;
    Node* right;
};

// Utility function to create a new Tree Node
Node* newNode(int val) {
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}


// Function to Build Tree
Node* buildTree(string str) {
    // Corner Case
    if (str.length() == 0 || str[0] == 'N') return NULL;

    // Creating vector of strings from input
    // string after spliting by space
    vector<string> ip;

    istringstream iss(str);
    for (string str; iss >> str;) ip.push_back(str);

    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));

    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);

    // Starting from the second element
    int i = 1;
    while (!queue.empty() && i < ip.size()) {

        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();

        // Get the current node's value from the string
        string currVal = ip[i];

        // If the left child is not null
        if (currVal != "N") {

            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->left);
        }

        // For the right child
        i++;
        if (i >= ip.size()) break;
        currVal = ip[i];

        // If the right child is not null
        if (currVal != "N") {

            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));

            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }

    return root;
}


 // } Driver Code Ends
/* Tree node structure  used in the program

struct Node {
    int data;
    Node *left;
    Node *right;

    Node(int val) {
        data = val;
        left = right = NULL;
    }
};*/

class Info{
    public:
    bool isbst;
    int minval,maxval,ans,size;
};

class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    Info sizeBst(Node* root)
    {
        if(root==NULL)
        {
            Info ob;
            ob.isbst=true;
            ob.minval=INT_MAX;
            ob.maxval=INT_MIN;
            ob.ans=0;
            ob.size=0;
            return ob;
        }
        if(root->left==NULL && root->right==NULL)
        {
            Info ob;
            ob.isbst=true;
            ob.minval=root->data;
            ob.maxval=root->data;
            ob.ans=1;
            ob.size=1;
            return ob;
        }
        Info l=sizeBst(root->left);
        Info r=sizeBst(root->right);
        Info ret;
        ret.size=1+l.ans+r.ans;
    	if(l.isbst && r.isbst && l.maxval<root->data && r.minval>root->data)
    	{
    	    ret.isbst=true;
    	    ret.maxval=max(max(l.maxval,root->data),r.maxval);
    	    ret.minval=min(min(r.minval,root->data),l.minval);
    	    ret.ans=ret.size;
    	    return ret;
    	} 
    	ret.isbst=false;
    	ret.ans=max(l.ans,r.ans);
    	return ret;
    }
    int largestBst(Node *root)
    {
    	//Your code here
        Info res=sizeBst(root);
        return res.ans;
    }
};

// { Driver Code Starts.

/* Driver program to test size function*/

  

int main() {

   
    int t;
    scanf("%d ", &t);
    while (t--) {
        string s, ch;
        getline(cin, s);
        
        Node* root = buildTree(s);
        Solution ob;
        cout << ob.largestBst(root) << endl;
    }
    return 0;
}
  // } Driver Code Ends