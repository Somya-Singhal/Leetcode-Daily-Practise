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
    //right-root-left(recursion)
    // int sum=0;
    // void helper(TreeNode* root)
    // {
    //     if(root==NULL)
    //         return;
    //     helper(root->right);
    //     root->val+=sum;
    //     sum=root->val;
    //     helper(root->left);
    //     return;
    // }
    // TreeNode* convertBST(TreeNode* root) {
    //     if(root==NULL)
    //         return 0;
    //     helper(root);
    //     return root;
    // }
    
    //stack
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        int sum=0;
        TreeNode* curr=root;
        stack<TreeNode*>s;
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->right;
            }
            curr=s.top();
            s.pop();
            curr->val+=sum;
            sum=curr->val;
            curr=curr->left;
        }
        return root;
    }
};