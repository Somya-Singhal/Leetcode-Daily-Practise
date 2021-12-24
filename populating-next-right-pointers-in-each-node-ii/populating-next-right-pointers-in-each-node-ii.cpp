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
    //time and space->O(n)
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
    //             if(i!=len-1)
    //                 curr->next=q.front();
    //             if(curr->left)
    //                 q.push(curr->left);
    //             if(curr->right)
    //                 q.push(curr->right);
    //         }
    //     }
    //     return root;
    // }
    
     Node* connect(Node* root) {
        if(root==NULL)
            return NULL;
         Node* curr=root,*prev=NULL,*head=NULL;
        while(curr!=NULL)
        {
            while(curr!=NULL)
            {
                if(curr->left)
                {
                    if(prev==NULL)
                        head=curr->left;
                    else
                    prev->next=curr->left;
                    prev=curr->left;
                }
                if(curr->right)
                {
                    if(prev==NULL)
                        head=curr->right;
                    else
                    prev->next=curr->right;
                    prev=curr->right;
                }
                curr=curr->next;
            }
            curr=head;
            head=NULL;
            prev=NULL;
        }
         return root;
    }
};