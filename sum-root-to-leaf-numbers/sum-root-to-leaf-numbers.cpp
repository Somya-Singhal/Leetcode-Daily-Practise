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
    int sumrec(TreeNode* root,int sum)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return 10*sum+root->val;
        int left=0,right=0;
        left=sumrec(root->left,10*sum+root->val);
        right=sumrec(root->right,10*sum+root->val);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return sumrec(root,0);
    }
};