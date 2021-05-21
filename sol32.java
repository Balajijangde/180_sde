/**
 * Definition for singly-linked list.
 * class ListNode {
 *     int val;
 *     ListNode next;
 *     ListNode(int x) {
 *         val = x;
 *         next = null;
 *     }
 * }
 */
public class Solution {
    public boolean hasCycle(ListNode head) {
        ListNode slow = head;
        ListNode fast = head;
        if(head == null)
            return false;
        do{
            slow = slow != null?slow.next:null;
            fast = (fast!= null && fast.next != null)?fast.next.next:null;
        }
        while(slow != fast);
        if(slow == null)
            return false;
        return true;
    }
}