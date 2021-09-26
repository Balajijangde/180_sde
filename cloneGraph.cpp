class Solution {
public:
    Node* cloneGraph(Node* node) {
        queue<Node*> myque;
        unordered_map<Node*, Node*> record;
        unordered_set<Node*> visited;
        
        if(node == nullptr) return nullptr;
        Node* head = new Node(node->val);
        record.insert({node, head});
        myque.push(node);
        while(!myque.empty()){
            cout<<"operating on "<<myque.front()->val<<endl;
            for(int i=0; i<myque.front()->neighbors.size(); i++){
                if(record.find(myque.front()->neighbors[i]) != record.end()){
                    cout<<"node already exists "<<myque.front()->neighbors[i]->val<<endl;
                    (record[myque.front()])->neighbors.push_back(record[myque.front()->neighbors[i]]);
                }else{
                    Node* last = new Node(myque.front()->neighbors[i]->val);
                    record.insert({myque.front()->neighbors[i], last});
                    record[myque.front()]->neighbors.push_back(last);
                    myque.push(myque.front()->neighbors[i]);
                    cout<<"adding node to list "<<last->val<<endl;
                }
            }
            visited.insert(myque.front());
            myque.pop();
        }
        return head;
    }
};