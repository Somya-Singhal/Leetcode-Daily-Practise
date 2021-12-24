/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    ListNode* midfunc(ListNode* head)
    {
        if(head==NULL)
            return NULL;
        ListNode* slow=head,*fast=head,*prev=NULL;
        while(fast!=NULL && fast->next!=NULL)
        {
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        if(prev!=NULL)
            prev->next=NULL;
        return slow;
    }
    TreeNode* sortedListToBST(ListNode* head) {
      if(head==NULL)
            return NULL;
      ListNode* mid=midfunc(head);
      TreeNode* root=new TreeNode(mid->val);
        if(head==mid)
            return root;
      root->left=sortedListToBST(head);
      root->right=sortedListToBST(mid->next);
      return root;
    }
};