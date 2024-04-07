/**
 * Definition for singly-linked list.
 * public class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode() {}
 *     ListNode(int val) { this.val = val; }
 *     ListNode(int val, ListNode next) { this.val = val; this.next = next; }
 * }
 */

class Solution {
    public ListNode getkthNode(ListNode node,int k){
    int count=k-1;
    while(node!=null){
        if(count==0)
            break;
        node=node.next;
        count-=1;
    }
    return node;
   }  
    public ListNode reverseNodes(ListNode start,ListNode end){
    ListNode p=start,q=start.next,r=null;
    while(p!=null && q!=null){
        r=q.next;
        q.next=p;
        if(p==start)
          p.next=null;
        p=q;
        q=r;
    }
    return end;
    }
    public ListNode reverseKGroup(ListNode head, int k) {
        ListNode temp=head,prev=null,nxt=null,newhead=null;
        while(temp!=null){
            ListNode kthNode=getkthNode(temp,k);
            if(kthNode==null){
                if(prev!=null){
                    prev.next=temp;
                }
                break;
            }
            nxt=kthNode.next;
            kthNode.next=null;
            ListNode rhead=reverseNodes(temp,kthNode);
            if(temp==head){
                newhead=kthNode;
            }else{
                prev.next=kthNode;
            }
            prev=temp;
            temp=nxt;
        }
       return newhead; 
    }
}