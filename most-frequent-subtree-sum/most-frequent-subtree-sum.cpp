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
    int frequentsum(TreeNode* root,unordered_map<int,int>& mp)
    {
        if(root==NULL)
            return 0;
        int sum=root->val;
        sum+=frequentsum(root->left,mp);
        sum+=frequentsum(root->right,mp);
        mp[sum]++;
        return sum;
    }
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int>mp;
        vector<int>res;
        frequentsum(root,mp);
        int currmax=INT_MIN;
        for(auto x:mp)
        {
            if(x.second>currmax)
                currmax=x.second;
        }
        for(auto x:mp)
        {
            if(x.second==currmax)
                res.push_back(x.first);
        }
        return res;
    }
};