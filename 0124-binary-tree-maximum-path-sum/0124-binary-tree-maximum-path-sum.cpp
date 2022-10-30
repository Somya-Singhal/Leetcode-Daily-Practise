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
    int solve(TreeNode* root,int *maxsum)
    {
        if(root==NULL)
            return 0;
        int left=max(solve(root->left,maxsum),0);
        int right=max(solve(root->right,maxsum),0);
        int currval=root->val+left+right;
        *maxsum=max(*maxsum,currval);
        return root->val+max(left,right);
    }
    int maxPathSum(TreeNode* root) {
        int maxsum=INT_MIN;
        solve(root,&maxsum);
        return maxsum;
    }
};