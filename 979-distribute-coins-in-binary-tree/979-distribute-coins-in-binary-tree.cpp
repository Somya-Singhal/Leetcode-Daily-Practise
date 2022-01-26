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
    int ans=0;
    void solve(TreeNode* root,TreeNode* parent) {
        if(root==NULL)
            return;
        solve(root->left,root);
       
        solve(root->right,root);
         if(root->val<=0 && parent!=NULL)
        {
            ans+=1-(root->val);
             parent->val-=(1-root->val);
        }
        else if(root->val>1 && parent!=NULL)
        {
            parent->val+=root->val-1;
            ans+=root->val-1;
            root->val=1;
        }
        return;
    }
    int distributeCoins(TreeNode* root) {
         solve(root,NULL);
         return ans;
    }
};