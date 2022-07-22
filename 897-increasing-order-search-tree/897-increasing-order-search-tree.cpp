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
    TreeNode* increasingBST(TreeNode* root) {
        if(root==NULL)
            return root;
        TreeNode *dummy=new TreeNode(0);
        TreeNode* head=dummy;
        stack<TreeNode*>s;
        TreeNode *curr=root;
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            dummy->right=new TreeNode(curr->val);
            dummy=dummy->right;
            curr=curr->right;
        }
        return head->right;
    }
};