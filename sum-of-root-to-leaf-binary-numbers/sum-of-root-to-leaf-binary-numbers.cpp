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
    int sumrec(TreeNode* root,int num)
    {
        if(root==NULL)
            return 0;
        if(root->left==NULL && root->right==NULL)
            return num*2+root->val;
        int sum=0;
        sum+=sumrec(root->left,num*2+root->val);
        sum+=sumrec(root->right,num*2+root->val);
        return sum;
    }
    int sumRootToLeaf(TreeNode* root) {
        return sumrec(root,0);
    }
};