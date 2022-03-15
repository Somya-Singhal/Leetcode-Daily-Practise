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
    TreeNode* constructTree(int pre_s,int pre_e,int post_s,int post_e,vector<int>& preorder,vector<int>& postorder,unordered_map<int,int>& m)
    {
        TreeNode* root=new TreeNode(preorder[pre_s]);
        if(pre_s==pre_e)
            return root;
        int idx=m[preorder[pre_s+1]];
        int len=idx-post_s+1;
        root->left=constructTree(pre_s+1,pre_s+len,post_s,post_s+len-1,preorder,postorder,m);
        if(idx+1==post_e)
            return root;
        root->right=constructTree(pre_s+len+1,pre_e,idx+1,post_e-1,preorder,postorder,m);
        return root;
    }
    TreeNode* constructFromPrePost(vector<int>& preorder, vector<int>& postorder) {
        int n=preorder.size();
        unordered_map<int,int>m;
        for(int i=0;i<n;i++)
        {
            m[postorder[i]]=i;
        }
        return constructTree(0,n-1,0,n-1,preorder,postorder,m);
    }
};