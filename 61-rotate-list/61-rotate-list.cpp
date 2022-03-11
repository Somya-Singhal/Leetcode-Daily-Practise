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
    //reverse before k nodes from left,reverse k node on right then reverse whole list together
    ListNode* rotateRight(ListNode* head, int k) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *curr=head;
        int count=0;
        while(curr!=NULL)
        {
            count++;
            curr=curr->next;
        }
        k=k%count;
        int i=count-k;
        ListNode *prev=NULL,*next=NULL;
        curr=head;
        while(i>0)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
            i--;
        }
        ListNode * newhead=prev;
        curr=next,prev=NULL,next=NULL;
        while(k-->0)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        head->next=prev;
        curr=newhead,next=NULL,prev=NULL;
        while(curr!=NULL)
        {
            next=curr->next;
            curr->next=prev;
            prev=curr;
            curr=next;
        }
        return prev;
    }
};