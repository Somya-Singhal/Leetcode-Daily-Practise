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
    int camera=0;
    int solve(TreeNode* root)
    {
        if(root==NULL)
            return 1;
        int lval=solve(root->left);
        int rval=solve(root->right);
        if(lval==-1 || rval==-1)
        {
            camera++;
            return 0;
        }
        if(lval==0 || rval==0)
            return 1;
        return -1;
    }
    int minCameraCover(TreeNode* root) {
        if(solve(root)==-1)
            camera++;
        return camera;
    }
};