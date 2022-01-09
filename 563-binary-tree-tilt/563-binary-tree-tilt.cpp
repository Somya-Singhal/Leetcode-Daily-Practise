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
    int calculate(TreeNode* root)
    {
        if(root==NULL)
            return 0;
        // int left=0,right=0;
        // if(mp.find(root->left)!=mp.end())
        //     left=mp[root->left];
        // else
            int left=calculate(root->left);
        // mp[root->left]=left;
        // if(mp.find(root->right)!=mp.end())
        //     right=mp[root->right];
        // else
        int right=calculate(root->right);
        // mp[root->right]=right;
        ans+=abs(left-right);
        return (root->val+left+right);
    }
    int findTilt(TreeNode* root) {
        if(root==NULL)
            return 0;
        calculate(root);
        return ans;
    }
};