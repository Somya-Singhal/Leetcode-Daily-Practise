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
    int ans=0;
    int sumSubTree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return (root->val+sumSubTree(root->left)+sumSubTree(root->right));
    }
    int calculate(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=0,right=0;
        left=sumSubTree(root->left);
        right=sumSubTree(root->right);
        ans+=abs(left-right);
        return (left+right);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        findTilt(root->left);
        calculate(root);
        findTilt(root->right);
        return ans;
    }
};