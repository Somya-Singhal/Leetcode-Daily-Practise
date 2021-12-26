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
    //recursion
    // vector<vector<int>>res;
    // void pathsumrec(TreeNode* root,int targetSum,vector<int>& ans)
    // {
    //     if(root==NULL)
    //         return;
    //     if(root->left==NULL && root->right==NULL && targetSum==root->val)
    //     {
    //         ans.push_back(root->val);
    //         res.push_back(ans);
    //         ans.pop_back();
    //         return;
    //     }
    //     if(root->left==NULL && root->right==NULL)
    //     return;
    //     ans.push_back(root->val);
    //     pathsumrec(root->left,targetSum-root->val,ans);
    //     pathsumrec(root->right,targetSum-root->val,ans);
    //     ans.pop_back();
    //     return;    
    // }
    // vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
    //     vector<int>ans;
    //    pathsumrec(root,targetSum,ans);
    //     return res;
    // }
    
    //queue or stack(same implementation)
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
       vector<vector<int>>res;
        if(root==NULL)
            return res;
        queue<pair<pair<TreeNode*,int>,vector<int>>>q;
        vector<int>ans;
        ans.push_back(root->val);
        q.push(make_pair(make_pair(root,root->val),ans));
        while(!q.empty())
        {
            pair<TreeNode*,int>p1;
            p1=q.front().first;
            vector<int>ans=q.front().second;
            TreeNode* curr=p1.first;
            int val=p1.second;
            q.pop();
            if(curr->left==NULL && curr->right==NULL && val==targetSum)
                res.push_back(ans);
            if(curr->left)
            {
                ans.push_back(curr->left->val);
                q.push(make_pair(make_pair(curr->left,val+curr->left->val),ans));
                ans.pop_back();
            }
            if(curr->right)
            {
                ans.push_back(curr->right->val);
                q.push(make_pair(make_pair(curr->right,val+curr->right->val),ans));
            }
        }
        return res;
    }
};