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
    int count=0;
    void solve(TreeNode* root,int largest)
    {
        if(root==NULL)
            return;
        int curr=max(largest,root->val);
        if(root->val>=largest)
            count+=1;
        solve(root->left,curr);
        solve(root->right,curr);
    }
    int goodNodes(TreeNode* root) {
        solve(root,INT_MIN);
        return count;
    }
};