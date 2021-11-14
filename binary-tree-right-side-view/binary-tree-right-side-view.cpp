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
    // tried recursive approach without queue using unordered_map
    void rightrec(TreeNode* root,map<int,int>& m,int level)
    {
        if(root==NULL)
            return;
        m[level]=root->val;
        rightrec(root->left,m,level+1);
        rightrec(root->right,m,level+1);
    }
    vector<int> rightSideView(TreeNode* root) {
        map<int,int>m;
        vector<int>res;
        rightrec(root,m,0);
        for(auto x: m)
        {
            res.push_back(x.second);
        }
        return res;
    }
};