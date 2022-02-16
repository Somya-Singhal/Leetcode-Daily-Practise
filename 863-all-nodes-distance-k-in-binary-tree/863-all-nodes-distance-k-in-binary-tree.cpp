/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    unordered_map<TreeNode*,int>mp;
    int path(TreeNode* root, TreeNode* target)
    {
        if(root==NULL)
            return -1;
        if(root==target)
        {
            mp[root]=0;
            return 0;
        }
            int l=path(root->left,target);
            if(l>=0)
            {
                mp[root]=l+1;
                return l+1;
            }
            int r=path(root->right,target);
            if(r>=0)
            {
                mp[root]=r+1;
                return r+1;
            }
        return -1;
    }
    void dfs(TreeNode* root, TreeNode* target,int level,int k,vector<int>& res)
    {
        if(root==NULL)
            return;
        if(mp.find(root)!=mp.end())
        level=mp[root];
        if(level==k)
        {
            res.push_back(root->val);
        }
        dfs(root->left,target,level+1,k,res);
        dfs(root->right,target,level+1,k,res);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int>res;
        path(root,target);
        dfs(root,target,mp[root],k,res);
        return res;
    }
};