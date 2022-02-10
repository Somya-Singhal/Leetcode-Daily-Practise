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
    ListNode* merge(ListNode* list1,ListNode* list2)
    {
        ListNode* a=list1,*b=list2,*tail=NULL,*fhead=NULL;
        while(a!=NULL && b!=NULL)
        {
            if(a->val<b->val)
            {
                if(fhead==NULL)
                {
                    fhead=a;
                    tail=a;
                }
                else
                {
                    tail->next=a;
                    tail=tail->next;
                }
                 a=a->next;
            }
            else
            {
                
                if(fhead==NULL)
                {
                    fhead=b;
                    tail=b;
                }
                else
                {
                    tail->next=b;
                    tail=tail->next;
                }
                 b=b->next;
            }
            if(a!=NULL)
                tail->next=a;
            if(b!=NULL)
                tail->next=b;
        }
        return fhead;
    }
    ListNode* divide(ListNode* curr)
    {
        if(curr==NULL || curr->next==NULL)
            return curr;
        ListNode* slow=NULL,*fast=curr;
        while(fast!=NULL && fast->next!=NULL)
        {
            slow=(slow==NULL)?curr:slow->next;
            fast=fast->next->next;
        }
        fast=slow->next;
        slow->next=NULL;
        ListNode* list1=divide(curr);
        ListNode* list2=divide(fast);
        return merge(list1,list2);
    }
    ListNode* sortList(ListNode* head) {
        return divide(head);
    }
};