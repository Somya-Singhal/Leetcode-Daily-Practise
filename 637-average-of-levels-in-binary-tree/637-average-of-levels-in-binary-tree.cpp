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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>avg;
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty())
        {
            int len=q.size();
            double average=0;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr=q.front();
                average+=curr->val;
                q.pop();
                if(curr->left!=NULL)
                    q.push(curr->left);
                if(curr->right!=NULL)
                    q.push(curr->right);
            }
            avg.push_back(average/len);
        }
        return avg;
    }
};