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
    //post-order traversal
    int sum=0;
    void helper(TreeNode* root)
    {
        if(root==NULL)
            return;
        helper(root->right);
        root->val+=sum;
        sum=root->val;
        helper(root->left);
        return;
    }
    TreeNode* convertBST(TreeNode* root) {
        if(root==NULL)
            return 0;
        helper(root);
        return root;
    }
};