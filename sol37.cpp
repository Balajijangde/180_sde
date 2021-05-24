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
    int getLength(ListNode* head){
        int count = 0;
        if(head == nullptr)
            return count;
        while(head != nullptr){
            head = head->next;
            count++;
        }
        return count;
    }
    
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode *p, *q;
        int move, length;
        length = getLength(head);
        
        if(length <= 1 || k == 0 || k == length){
            return head;
        }
        if(k > length){
            k = k%length;
        }
        if(k == 0)
            return head;
        move = length - k -1;
        p = head;
        for(int i = 0; i<move; i++){
            p = p->next;
        }
        q = p->next;
        p->next = nullptr;
        p = q;
        while(p->next != nullptr){
            p = p->next;
        }
        p->next = head;
        return q;
        
    }
};