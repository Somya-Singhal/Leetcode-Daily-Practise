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
    int count=1;
    void goodrec(TreeNode* root,int curr_max)
    {
        if(root==NULL)
            return;
        if(root->val>curr_max)
        {
            curr_max=root->val;
        }
        if(curr_max<=root->val)
            count++;
        goodrec(root->left,curr_max);
        goodrec(root->right,curr_max);
            
    }
    int goodNodes(TreeNode* root) {
        goodrec(root->left,root->val);
        goodrec(root->right,root->val);
        return count;
    }
};