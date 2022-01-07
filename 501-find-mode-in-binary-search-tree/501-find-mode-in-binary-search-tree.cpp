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
    void countofElements(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return;
        mp[root->val]++;
        countofElements(root->left,mp);
        countofElements(root->right,mp);
        return;
    }
    vector<int> findMode(TreeNode* root) {
        vector<int>res;
        unordered_map<int,int>mp;
        countofElements(root,mp);
        int countmax=INT_MIN;
        for(auto x: mp)
        {
           if(countmax<x.second)
           {
               res.clear();
               res.push_back(x.first);
               countmax=x.second;
           }
            else if(countmax==x.second)
                res.push_back(x.first);
        }
        return res;
    }
};