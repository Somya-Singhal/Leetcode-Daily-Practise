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
    int getMinimumDifference(TreeNode* root) {
        if(root==NULL)
            return 0;
        int ans=INT_MAX;
        stack<TreeNode*>s;
        TreeNode* curr=root,*prev=NULL;
        while(curr!=NULL || !s.empty())
        {
            while(curr!=NULL)
            {
                s.push(curr);
                curr=curr->left;
            }
            curr=s.top();
            s.pop();
            if(prev!=NULL)
            {
                ans=min(ans,curr->val-prev->val);
            }
            prev=curr;
            curr=curr->right;
        }
        return ans;
    }
};