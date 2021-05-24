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
    ListNode* reverse(ListNode* head, int m){    
        ListNode *p1, *p2, *p3; 
        p1 = head;
        p2 = p1->next;
        p3 = p2->next;
        p1->next = nullptr;
        for(int i = 1; i<m; i++){
            p2->next = p1;
            p1 = p2;
            p2 = p3;
            p3 = p3!=nullptr?p3->next:nullptr;
        }
        return p1;
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        if(k == 1)
            return head;
        ListNode *prev, *tail, *cur;
        ListNode root = ListNode(0, head);
        prev = &root;
        cur = head;
        tail = cur;
        bool stop = false;
        while(cur!=nullptr){
            
            
            for(int i=0; i<k; i++){
                if(cur == nullptr){
                    stop = true;
                    break;
                }
                cur = cur->next;
            }
            if(stop == true){
                break;
            }
            prev->next = reverse(tail, k);
            prev = tail;
            tail = cur;
        }
        prev->next = tail;
        return root.next;
    }
};