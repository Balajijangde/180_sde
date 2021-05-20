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
    public ListNode removeNthFromEnd(ListNode head, int n) {
        ListNode myhead = new ListNode(0, head);
        ListNode slow = myhead;
        ListNode fast = myhead;
        
        for(int i=1; i<=n; i++){
            fast = fast.next;
        }
        while(fast.next != null){
            fast = fast.next;
            slow = slow.next;
        }
        if(slow.next.next == null){
            slow.next = null;
            return myhead.next;
        }
        slow.next = slow.next.next;
        return myhead.next;
    }
}