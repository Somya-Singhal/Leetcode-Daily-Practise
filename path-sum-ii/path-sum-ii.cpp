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
    vector<vector<int>>res;
    void pathsumrec(TreeNode* root,int targetSum,vector<int>& ans)
    {
        if(root==NULL)
            return;
        if(root->left==NULL && root->right==NULL && targetSum==root->val)
        {
            ans.push_back(root->val);
            res.push_back(ans);
            ans.pop_back();
            return;
        }
        if(root->left==NULL && root->right==NULL)
        return;
        ans.push_back(root->val);
        pathsumrec(root->left,targetSum-root->val,ans);
        pathsumrec(root->right,targetSum-root->val,ans);
        ans.pop_back();
        return;    
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int>ans;
       pathsumrec(root,targetSum,ans);
        return res;
    }
};