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
    ListNode* deleteMiddle(ListNode* head) {
        int len=0;
        ListNode *curr=head;
        if(head->next==NULL)
            return NULL;
        while(curr!=NULL)
        {
            len+=1;
            curr=curr->next;
        }
        ListNode *prev=NULL;
        curr=head;
        int count=0;
        while(count!=len/2)
        {
            prev=curr;
            curr=curr->next;
            count+=1;
        }
        prev->next=curr->next;
        return head;
    }
};