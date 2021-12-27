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
    int leftdist(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+leftdist(root->left);
    }
    int rightdist(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return 1+rightdist(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root!=NULL)
        {
            int left=leftdist(root->left);
            int right=rightdist(root->right);
            if(left==right)
                return pow(2,left+1)-1;
            else 
                return 1+countNodes(root->left)+countNodes(root->right);
        }
        return 0;
    }
};