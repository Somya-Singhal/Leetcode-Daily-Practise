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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        int carry=0;
        ListNode *prev=NULL,*head=NULL;
        while(l1!=NULL || l2!=NULL)
        {
            int num=(l1!=NULL?l1->val:0)+(l2!=NULL?l2->val:0)+carry;
            ListNode *newnode=new ListNode(num%10);
            carry=num/10;
            if(prev==NULL)
            {
                prev=newnode;
                head=prev;
            }
            else
            {
                prev->next=newnode;
                prev=prev->next;
            }
            if(l1)
            l1=l1->next;
            if(l2)
            l2=l2->next;
        }
        if(carry)
        {
            ListNode *newnode=new ListNode(carry);
            prev->next=newnode;
        }
        return head;
    }
};