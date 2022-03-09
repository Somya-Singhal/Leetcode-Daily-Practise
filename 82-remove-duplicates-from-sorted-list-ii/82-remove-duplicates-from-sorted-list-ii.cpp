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
    // ListNode* deleteDuplicates(ListNode* head) {
    //     if(head==NULL || head->next==NULL)
    //         return head;
    //     ListNode *curr=head->next,*prev=head;
    //     unordered_set<int>s;
    //     while(curr!=NULL)
    //     {
    //         if(curr->val==prev->val)
    //         {
    //             ListNode *temp=curr;
    //             s.insert(curr->val);
    //             curr=curr->next;
    //             prev->next=curr;
    //             delete temp;
    //         }
    //         else
    //         {
    //             prev=prev->next;
    //             curr=curr->next;
    //         }
    //     }
    //     curr=head,prev=NULL;
    //     while(curr!=NULL)
    //     {
    //         if(s.find(curr->val)!=s.end())
    //         {
    //             if(curr==head)
    //             {
    //                 head=head->next;
    //                 prev=curr;
    //                 curr=curr->next;
    //             }
    //             else
    //             {
    //                 curr=curr->next;
    //                 prev->next=curr;
    //             }
    //         }
    //         else
    //         {
    //             prev=curr;
    //             curr=curr->next;   
    //         }
    //     }
    //     return head;
    // }
    ListNode* deleteDuplicates(ListNode* head) {
        if(head==NULL || head->next==NULL)
            return head;
        ListNode *dummy=new ListNode(0);
        ListNode *curr=dummy;
        dummy->next=head;
       while(head!=NULL)
       {
          if(head->next!=NULL && head->val==head->next->val)
          {
             while(head->next!=NULL && head->val==head->next->val)
                 head=head->next;
                  
            curr->next=head->next;
          }
           else
           {
               curr=head;
           }
           head=head->next;
       }
        return dummy->next;
    }
};