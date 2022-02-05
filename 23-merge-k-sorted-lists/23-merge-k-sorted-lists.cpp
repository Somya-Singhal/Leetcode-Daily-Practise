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
    //merge sort
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        int n=lists.size();
        if(n==0)
            return NULL;
        return merge(0,n-1,lists);
    }
    ListNode* merge(int start,int end,vector<ListNode*>& lists)
    {
        if(end<start)
            return NULL;
        if(start==end)
            return lists[start];
        if(start+1==end)
            return mergetwolist(lists[start],lists[end]);
        int mid=(start+end)/2;
        ListNode* first=merge(start,mid,lists);
        ListNode* second=merge(mid+1,end,lists);
        return mergetwolist(first,second);
    }
    ListNode* mergetwolist(ListNode* head1,ListNode* head2)
    {
        if(head1==NULL)
            return head2;
        if(head2==NULL)
            return head1;
        if(head1->val<=head2->val)
        {
            head1->next=mergetwolist(head1->next,head2);
            return head1;
        }
        else
        {
            head2->next=mergetwolist(head1,head2->next);
            return head2;
        }
            
    }
};