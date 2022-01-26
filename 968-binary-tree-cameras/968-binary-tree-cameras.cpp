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
    // int camera=0;
    // int solve(TreeNode* root)
    // {
    //     if(root==NULL)
    //         return 1;
    //     int lval=solve(root->left);
    //     int rval=solve(root->right);
    //     if(lval==-1 || rval==-1)
    //     {
    //         camera++;
    //         return 0;
    //     }
    //     if(lval==0 || rval==0)
    //         return 1;
    //     return -1;
    // }
    // int minCameraCover(TreeNode* root) {
    //     if(solve(root)==-1)
    //         camera++;
    //     return camera;
    // }
    
    //greedy->intuitive sol :)//
    int ans=0;
    unordered_set<TreeNode*>covered;
    void solve(TreeNode* root,TreeNode* par)
    {
        if(root!=NULL)
        {
            solve(root->left,root);
            solve(root->right,root);
        if((par==NULL && covered.find(root)==covered.end()) || (covered.find(root->left)==covered.end() || covered.find(root->right)==covered.end()))
        {
            ans++;
            covered.insert({root});
            covered.insert({par});
            covered.insert({root->left});
            covered.insert({root->right});
        }
        }
    }
    int minCameraCover(TreeNode* root) {
        covered.insert({NULL});
        solve(root,NULL);
        return ans;
      }
};