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
    int widthOfBinaryTree(TreeNode* root) {
        unsigned long long maxWidth=1;
        queue<pair<TreeNode*,unsigned long long>>q;
        q.push({root,0});
        while(!q.empty())
        {
            int len=q.size();
            unsigned long long leftidx=0,rightidx=0;
            for(int i=0;i<len;i++)
            {
                TreeNode* curr=q.front().first;
                unsigned long long idx=q.front().second;
                q.pop();
                if(i==0)
                    leftidx=idx;
                if(i==len-1)
                    rightidx=idx;
                if(curr->left)
                    q.push({curr->left,2*idx+1});
                if(curr->right)
                    q.push({curr->right,2*idx+2});
            }
            maxWidth=max(maxWidth,rightidx-leftidx+1);
        }
        return maxWidth;
    }
};