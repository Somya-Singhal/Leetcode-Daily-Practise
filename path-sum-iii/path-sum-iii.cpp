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
    int res=0;
    void seconddfs(TreeNode* root,int targetSum)
    {
        if(root==NULL)
            return;
        targetSum-=root->val;
        if(targetSum==0)
            res++;
        seconddfs(root->left,targetSum);
        seconddfs(root->right,targetSum);
    }
    void firstdfs(TreeNode* root,int targetSum)
    {
        if(root==NULL)
            return;
        seconddfs(root,targetSum);
        firstdfs(root->left,targetSum);
        firstdfs(root->right,targetSum);
    }
    int pathSum(TreeNode* root, int targetSum) {
       if(root==NULL)
            return 0;
       firstdfs(root,targetSum);
       return res;
    }
};