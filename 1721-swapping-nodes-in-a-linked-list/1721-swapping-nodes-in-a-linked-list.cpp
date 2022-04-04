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
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode* temp=head;
        int count=0;
        while(temp!=NULL){
            count++;
            temp=temp->next;
        }
        temp=head;
        ListNode* l1=NULL,*l2=NULL;
        int start=0;
        while(temp!=NULL){
           start++;
            if(start==k)
                l1=temp;
            if(start==count-k+1)
                l2=temp;
            temp=temp->next;
        }
        if(l1!=NULL && l2!=NULL)
        swap(l1->val,l2->val);
        return head;
    }
};