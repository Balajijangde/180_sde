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
    public ListNode addTwoNumbers(ListNode l1, ListNode l2) {
        ListNode result = new ListNode(0);
        ListNode head = result;
        int sum = 0;
        int carry = 0;
        while(l1 != null || l2 != null || carry != 0){
            sum = (l1!=null?l1.val:0) + (l2!=null?l2.val:0) + carry;
            carry = 0;
            if(sum > 9){
                carry = sum/10;
                sum = sum%10;
            }
            result.next = new ListNode(sum);
            result = result.next;
            l1 = l1 != null?l1.next:null;
            l2 = l2 != null?l2.next:null;
            
        }
        return head.next;
    }
}