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
    // void countofElements(TreeNode* root,unordered_map<int,int>& mp)
    // {
    //     if(root==NULL)
    //         return;
    //     mp[root->val]++;
    //     countofElements(root->left,mp);
    //     countofElements(root->right,mp);
    //     return;
    // }
    // vector<int> findMode(TreeNode* root) {
    //     vector<int>res;
    //     unordered_map<int,int>mp;
    //     countofElements(root,mp);
    //     int countmax=INT_MIN;
    //     for(auto x: mp)
    //     {
    //        if(countmax<x.second)
    //        {
    //            res.clear();
    //            res.push_back(x.first);
    //            countmax=x.second;
    //        }
    //         else if(countmax==x.second)
    //             res.push_back(x.first);
    //     }
    //     return res;
    // }
    
    //without extra space(except recursion)-->inorder traversal
    int maxcount=0,currcount=0,currval;
     vector<int>res;
    void inorder(TreeNode* root)
    {
        if(root==NULL)
            return;
        inorder(root->left);
        countofElements(root->val);
        inorder(root->right);
    }
     void countofElements(int value)
    {
        if(value!=currval)
        {
            currval=value;
            currcount=0;
        }
        currcount++;
        if(currcount>maxcount)
        {
            res.clear();
            res.push_back(currval);
            maxcount=currcount;
        }
        else if(currcount==maxcount)
        {
            res.push_back(currval);
        }
    }
    vector<int> findMode(TreeNode* root) {
        inorder(root);
        return res;
    }
};