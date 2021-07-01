class Node {
public:
	Node(pair<int, int> val) {
		this->value = val;
	}
	pair<int, int> value;
	Node* next = nullptr;
	Node* previous = nullptr;
};
class DoublyLinkedList {
public:
	Node* head;
	Node* tail;
	DoublyLinkedList() {
		head = new Node({0,0});
		tail = new Node({0,0});
		head->next = tail;
		head->previous = nullptr;
		tail->next = nullptr;
		tail->previous = head;
	}
	Node* push_front(pair<int, int> val) {
		Node* dummy = head->next;
		Node* newNode = new Node(val);
		head->next = newNode;
		newNode->next = dummy;
		dummy->previous = newNode;
		newNode->previous = head;
		return newNode;
	}
	int pop_back() {
		int last_value = tail->previous->value.first;
		Node* dummy = tail->previous->previous;
		Node* todelete = tail->previous;
		dummy->next = tail;
		tail->previous = dummy;
		delete todelete;
		return last_value;
	}
	void deleteNode(Node* node) {
		Node* first = node->previous;
		Node* last = node->next;
		first->next = last;
		last->previous = first;
		delete node;
	}
};
class LRUCache {
public:
	int capacity = 0;
	int size = 0;
	DoublyLinkedList ddl;
	unordered_map<int, Node*> mymap;
	LRUCache(int capacity) {
		this->capacity = capacity;
	}

	int get(int key) {
		if (mymap.find(key) != mymap.end()) {
			int k = mymap[key]->value.first;
			int l = mymap[key]->value.second;
			ddl.deleteNode(mymap[key]);
			Node* dum = ddl.push_front({ k,l });
			mymap[k] = dum;
			return l;
		}
		else {
			return -1;
		}
	}

	void put(int key, int value) {
		if (mymap.find(key) != mymap.end()) {
			//key already exists
			ddl.deleteNode(mymap[key]);
			Node* entry = ddl.push_front({ key, value });
			mymap[key] = entry;
		}
		else {
			//key doesn't exists
			if (size == capacity) {
				//list is full
				
				mymap.erase(ddl.pop_back());
				Node* entry = ddl.push_front({ key, value });
				mymap.insert({ key, entry });
			}
			else {
				//list has space
				size++;
				Node* entry = ddl.push_front({key, value});
				mymap.insert({key, entry});
			}
		}
	}
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */