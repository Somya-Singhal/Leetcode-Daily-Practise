/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
   //time->O(width of tree),Space->O(width of tree)
    // Node* connect(Node* root) {
    //     if(root==NULL)
    //         return NULL;
    //     queue<Node*>q;
    //     q.push(root);
    //     while(!q.empty())
    //     {
    //         int len=q.size();
    //         for(int i=0;i<len;i++)
    //         {
    //             Node* curr=q.front();
    //             q.pop();
    //             if(i!=len-1) curr->next=q.front();
    //             if(curr->left) q.push(curr->left);
    //             if(curr->right) q.push(curr->right);
    //         }
    //     }
    //     return root;
    // }
    
    //time->O(n),Space->O(1)
     Node* connect(Node* root) {
       if(root!=NULL)
       {
           if(root->left)
               root->left->next=root->right;
           if(root->next && root->next->left)
               root->right->next=root->next->left;
           connect(root->left);
           connect(root->right);
       }
         return root;
    }
};
