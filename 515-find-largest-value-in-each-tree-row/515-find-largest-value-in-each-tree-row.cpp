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
    vector<int> largestValues(TreeNode* root) {
        if(root==NULL)
            return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<int>res;
        while(!q.empty())
        {
            int len=q.size();
            int rowmax=INT_MIN;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr=q.front();
                q.pop();
                rowmax=max(rowmax,curr->val);
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
                
            }
            res.push_back(rowmax);
        }
        return res;
    }
};