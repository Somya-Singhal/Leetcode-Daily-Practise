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
    // int maxpath=0;
    // int longestPath(TreeNode* root)
    // {
    //     if(root==NULL)
    //         return 0;
    //     int pathLeft=0,pathRight=0,totalSum=0,currmax=0;
    //     if(root->left && root->right)
    //     {
    //         if(root->left->val==root->right->val && root->left->val==root->val)
    //             totalSum=2+longestPath(root->left)+longestPath(root->right);
    //     }
    //     if(root->left && root->left->val==root->val)
    //          pathLeft=1+longestPath(root->left);
    //     if(root->right && root->right->val==root->val)
    //          pathRight=1+longestPath(root->right);
    //     int leftval=longestPath(root->left);
    //     int rightval=longestPath(root->right);
    //     currmax=max(pathLeft,pathRight);
    //     maxpath=max(max(max(max(maxpath,totalSum),currmax),leftval),rightval);
    //     return currmax;
    // }
    // int longestUnivaluePath(TreeNode* root) {
    //    if(root==NULL)
    //         return 0;
    //    longestPath(root); 
    //    return maxpath;
    // }
     int maxpath=0;
    int longestPath(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int leftPath=longestPath(root->left);
        int rightPath=longestPath(root->right);
        int leftVal=0,rightVal=0;
        if(root->left && root->left->val==root->val)
          leftVal=1+leftPath;
        if(root->right && root->right->val==root->val)
          rightVal=1+rightPath;
        maxpath=max(maxpath,leftVal+rightVal);
        return max(leftVal,rightVal);
        
    }
    int longestUnivaluePath(TreeNode* root) {
       if(root==NULL)
            return 0;
       longestPath(root); 
       return maxpath;
    }
};