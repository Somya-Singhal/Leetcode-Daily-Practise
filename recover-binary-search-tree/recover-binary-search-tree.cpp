/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        //stack used->O(n)
    // void recoverTree(TreeNode* root) {
    //     TreeNode* first=NULL,*second=NULL,*curr=root,*prev=NULL;
    //     stack<TreeNode*>s;
    //     while(curr || !s.empty())
    //     {
    //         while(curr!=NULL)
    //         {
    //            s.push(curr);
    //            curr=curr->left;
    //         }
    //         curr=s.top();
    //         s.pop();
    //         if(first!=NULL && second!=NULL && first->val>curr->val)
    //             second=curr;
    //         else if(prev!=NULL && prev->val>curr->val)
    //         {
    //             first=prev;
    //             second=curr;
    //         }
    //         prev=curr;
    //         curr=curr->right;
    //     }
    //     int temp=first->val;
    //     first->val=second->val;
    //     second->val=temp;
    //     return;
    // }
    
    //recursive inorder
    TreeNode* prev=NULL,*first=NULL,*second=NULL;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        if(first!=NULL && second!=NULL && first->val>root->val)
                second=root;
        else if(prev && prev->val>root->val)
        {
            first=prev;
            second=root;
        }
        prev=root;
        inorder(root->right);
        return;
    }
    void recoverTree(TreeNode* root) {
        if(root==NULL)
            return;
        inorder(root);
        int temp=first->val;
        first->val=second->val;
        second->val=temp;
        return;
    }
};
