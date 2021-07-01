class Node {
public:
    int key = 0;
    int value = 0;
    int frequency = 1;
    Node* next = nullptr;
    Node* previous = nullptr;
    Node(int k, int v) {
        key = k;
        value = v;
    }
};
class DoubleLinkedList {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    DoubleLinkedList() {
        head = new Node(0, 0);
        tail = new Node(0, 0);
        head->next = tail;
        tail->previous = head;
    }
    Node* push_front(int k, int v) {
        Node* dummy = head->next;
        Node* newNode = new Node(k, v);
        head->next = newNode;
        newNode->next = dummy;
        dummy->previous = newNode;
        newNode->previous = head;
        return newNode;
    }
    int pop_back() {
        Node* dummy = tail->previous->previous;
        Node* todelete = tail->previous;
        int key = todelete->key;
        dummy->next = tail;
        tail->previous = dummy;
        delete todelete;
        return key;
    }
    void delete_node(Node* node) {
        Node* front = node->previous;
        Node* back = node->next;
        front->next = back;
        back->previous = front;
        Node deleted(node->key, node->value);
        deleted.frequency = node->frequency;
        delete node;
        
    }
};
class LFUCache {
public:
    int capacity = 0;
    int size = 0;
    int minfreq = 1;
    unordered_map<int, Node*> nodes;
    unordered_map<int, DoubleLinkedList*> frequency;

    LFUCache(int capacity) {
        this->capacity = capacity;
    }
    int get(int key) {
        if (nodes.find(key) == nodes.end()) {
            return -1;
        }
        else {
            
            //make copy of node (updated frequency)
            Node* node = nodes[key];
            int key = node->key;
            int value = node->value;
            int freq = node->frequency;
            freq++;
            //delete it from nodes
            nodes.erase(key);
            //delete it from frequency tables
            DoubleLinkedList* ddl_old = frequency[freq - 1];
            ddl_old->delete_node(node);
            //push front to new frequency ddl
            if (frequency.find(freq) == frequency.end()) {
                frequency[freq] = new DoubleLinkedList();
            }
            DoubleLinkedList* ddl_new = frequency[freq];
            Node* newNode = ddl_new->push_front(key, value);
            newNode->frequency = freq;
            //update nodes
            nodes.insert({ key, newNode });
            //check for empty frequency ddl
            if ((freq-1)==minfreq && ddl_old->head->next == ddl_old->tail)
                minfreq++;
            return newNode->value;
        }
    }

    void put(int key, int value) {
        if (nodes.find(key) != nodes.end()) {

            int freq = nodes[key]->frequency;
            freq++;
            Node* node = nodes[key];
            DoubleLinkedList* old_ddl = frequency[freq - 1];
            old_ddl->delete_node(node);
            nodes.erase(key);
            if (frequency.find(freq) == frequency.end()) {
                frequency.insert({ freq, new DoubleLinkedList() });
            }
            DoubleLinkedList* new_ddl = frequency[freq];
            Node* newNode = new_ddl->push_front(key, value);
            newNode->frequency = freq;
            nodes.insert({ key, newNode });
            if ((freq-1)==minfreq && old_ddl->head->next == old_ddl->tail)
                minfreq++;
        }
        else {
            if (size == capacity) {
                //non existing node but space full
                if (size == 0) return;
                DoubleLinkedList* ddl = frequency[minfreq];
                Node* toremove = ddl->tail->previous;
                nodes.erase(toremove->key);
                ddl->pop_back();
                

                ddl = frequency[1];
                Node* newNode = ddl->push_front(key, value);
                nodes.insert({ key, newNode });
                minfreq = 1;
                
            }
            else {
                //non existing node and space left
                size++;
                if (frequency.find(1) == frequency.end()) {
                    frequency.insert({ 1, new DoubleLinkedList() });
                }
                DoubleLinkedList* ddl = frequency[1];
                Node* newNode = ddl->push_front(key, value);
                nodes.insert({ key, newNode });
                minfreq = 1;
            }

        }
    }
};
/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */