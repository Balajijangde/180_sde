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
    ListNode* reverseList(ListNode* head) {
        ListNode* pointerA = nullptr;
        ListNode* pointerB = head;
        ListNode* pointerC = head != nullptr?head->next:nullptr;
        
        while(pointerB != nullptr){
            pointerB->next = pointerA;
            pointerA = pointerB;
            pointerB = pointerC;
            pointerC = pointerC != nullptr?pointerC->next:nullptr;
        }
        return pointerA;
    }
};