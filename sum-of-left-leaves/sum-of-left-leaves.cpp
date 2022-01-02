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
   
    int sumOfLeftLeaves(TreeNode* root) {
        int ans=0;
       stack<TreeNode*>s;
       s.push(root);
        while(!s.empty())
        {
           TreeNode* curr=s.top();
           s.pop();
           if(curr->right!=NULL)
               s.push(curr->right);
           if(curr->left!=NULL && curr->left->left==NULL && curr->left->right==NULL)
               ans+=curr->left->val;
           else if(curr->left!=NULL)
            s.push(curr->left);
        }
        return ans;
    }
};