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
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        ListNode p1, p2, tmp, head, dummy;
        if(l1 == null && l2 != null){
            return l2;
        }else if(l1 != null && l2 == null){
            return l1;
        }else if(l1 == null && l2 == null){
            return null;
        }
        if(l1.val <= l2.val){
            p1 = l1;
            head = l1;
            p2 = l2;
        }else{
            head = l2;
            p1 = l2;
            p2 = l1;
        }
        tmp = p1;
        while(p1 != null){
            if(p1.val <= p2.val){
                tmp = p1;
                p1 = p1.next;
            }else{
                tmp.next = p2;
                dummy = p1;
                p1 = p2;
                p2 = dummy;
                tmp = null;
                
            }
        }
        tmp.next = p2;
        return head;
    }
}
