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
    unordered_map<string,int>mp;
    string Subtrees(TreeNode* root,vector<TreeNode*>& res)
    {
        
        if(root==NULL)
            return "#";
        string str=to_string(root->val)+","+Subtrees(root->left,res)+","+Subtrees(root->right,res);
        cout<<str<<"\n";
        mp[str]++;
        if(mp.find(str)!=mp.end() && mp[str]==2)
            res.push_back(root);
        return str;
    }
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        if(root==NULL)
            return {};
         vector<TreeNode*>res;
        Subtrees(root,res);
        return res;
    }
};