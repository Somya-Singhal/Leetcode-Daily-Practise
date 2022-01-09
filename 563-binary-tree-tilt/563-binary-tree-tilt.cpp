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
    // unordered_map<TreeNode*,int>mp;
    int sumSubTree(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        return (root->val+sumSubTree(root->left)+sumSubTree(root->right));
    }
    int calculate(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        int left=0,right=0;
        // if(mp.find(root->left)!=mp.end())
        //     left=mp[root->left];
        // else
            left=sumSubTree(root->left);
        // mp[root->left]=left;
        // if(mp.find(root->right)!=mp.end())
        //     right=mp[root->right];
        // else
        right=sumSubTree(root->right);
        // mp[root->right]=right;
        ans+=abs(left-right);
        return (left+right);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        findTilt(root->left);
        findTilt(root->right);
        calculate(root);
        return ans;
    }
};