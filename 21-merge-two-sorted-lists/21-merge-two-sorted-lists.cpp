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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode *a=list1,*b=list2,*head=NULL,*tail=NULL;
        if(a==NULL)
            return b;
        if(b==NULL)
            return a;
        while(a!=NULL && b!=NULL)
        {
            if(a->val<=b->val)
            {
                if(head==NULL)
                {
                    head=tail=a;
                }
                else
                {
                    tail->next=a;
                    tail=tail->next;
                }
                a=a->next;
            }
            else{
                if(head==NULL)
                {
                    head=tail=b;
                }
                else
                {
                    tail->next=b;
                    tail=tail->next;
                }
                b=b->next;
            }
        }
        if(a!=NULL)
        {
            tail->next=a;
        }
        if(b!=NULL)
        {
            tail->next=b;
        }
        return head;
    }
};