/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)
            return NULL;
        
        Node *front, *back, *newHead, *extra;
        front = back = head;
        //step 1 : creating new nodes
        while(back != NULL){
            front = back->next;
            back->next = new Node(back->val);
            back=back->next;
            back->next = front;
            back = front;
        }
        front = back = head;
        //step 2: settle random pointers
        while(back != NULL){
            front = front->next;
            back = back->random;
            back = back == NULL?NULL:back->next;
            front->random = back;
            front= front->next;
            back = front;
        }
        
        //step 3: settle next pointers
        newHead = head->next;
        front = head->next;
        back = head;
        while(back != NULL){
            back->next = front!=NULL?front->next:NULL;
            back = front->next;
            front->next = back!=NULL?back->next:NULL;
            front = front!=NULL?front->next:NULL;
        }
        return newHead;
    }
};