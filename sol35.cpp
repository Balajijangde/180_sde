/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode *slow, *fast;
        slow = head;
        fast = head;
        do{
            if(slow == nullptr || fast == nullptr)
                return NULL;
            slow = slow!=nullptr?slow->next:nullptr;
            fast = (fast != nullptr && fast->next != nullptr)?fast->next->next:nullptr;
        }while(slow != fast);
        fast = head;
        if(slow == nullptr || fast == nullptr)
                return NULL;
        while(slow != fast){
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
        
    }
};