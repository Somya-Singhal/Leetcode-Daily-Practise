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
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *next=head,*prev=NULL,*curr=head;
        for(int i=0;i<n;i++)
        {
            if(curr==NULL)
                break;
            curr=curr->next;     
        }
        while(curr!=NULL)
        {
            prev=next;
            curr=curr->next;
            next=next->next;
        }
        if(prev!=NULL)
        prev->next=next->next;
        return prev==NULL?head->next:head;
    }
};