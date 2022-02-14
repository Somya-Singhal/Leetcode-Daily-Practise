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
    int maxlength=INT_MIN;
    void dfs(TreeNode* root,int currlen)
    {
        if(root==NULL)
        {
            maxlength=max(maxlength,currlen);
            return;
        }
        dfs(root->left,currlen+1);
        dfs(root->right,currlen+1);
        return;
    }
    int maxDepth(TreeNode* root) {
        if(root==NULL)
            return 0;
        // queue<TreeNode*>q;
        // q.push(root);
        // int count=0;
        // while(!q.empty())
        // {
        //     int len=q.size();
        //     for(int i=0;i<len;i++)
        //     {
        //         TreeNode* curr=q.front();
        //         q.pop();
        //         if(curr->left)
        //             q.push(curr->left);
        //         if(curr->right)
        //             q.push(curr->right);
        //     }
        //    count++; 
        // }
        // return count;
        dfs(root,0);
        return maxlength;
    }
};