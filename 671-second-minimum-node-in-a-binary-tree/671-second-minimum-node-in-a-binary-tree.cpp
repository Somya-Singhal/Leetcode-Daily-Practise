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
    int findSecondMinimumValue(TreeNode* root) {
        queue<TreeNode*>q;
        q.push(root);
        int first=-1,second=-1;
        while(!q.empty())
        {
            int len=q.size();
            for(int i=0;i<len;i++)
            {
                TreeNode* curr=q.front();
                if(first==-1)
                    first=curr->val;
                else
                {
                    if(curr->val<first)
                    {
                        second=first;
                        first=curr->val;
                    }
                    else{
                        if((second==-1 || second>curr->val) && curr->val!=first)
                            second=curr->val;
                    }
                }
                q.pop();
                if(curr->left)
                    q.push(curr->left);
                if(curr->right)
                    q.push(curr->right);
            }
        }
        return second;
    }
};