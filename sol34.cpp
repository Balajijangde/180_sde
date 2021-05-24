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
private:
    ListNode* reverse(ListNode* head){
        if(head == nullptr)
            return nullptr;
        ListNode *pre, *cur, *nex;
        pre = nullptr;
        cur = head;
        nex = head->next;
        while(cur != nullptr){
            cur->next = pre;
            pre = cur;
            cur = nex;
            nex = nex!=nullptr?nex->next:nullptr;
        }
        return pre;
    }
public:
    bool isPalindrome(ListNode* head) {
        ListNode *slow, *fast, *head1, *head2;
        slow = fast = head;
        while(fast != nullptr && fast->next != nullptr){
            slow = slow != nullptr?slow->next:nullptr;
            fast = (fast != nullptr && fast->next != nullptr)?fast->next->next:nullptr;
        }
        head1 = head;
        head2 = reverse(slow);
        while(head1 != nullptr && head2 != nullptr){
            if(head1->val != head2->val){
                return false;
            }
            head1 = head1->next;
            head2 = head2->next;
        }
        return true;
    }
};