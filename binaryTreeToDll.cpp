class Solution
{
    public: 
    void recur(Node* root, Node*& head, Node*& previous){
        if(root == nullptr) return;
        
        recur(root->left, head, previous);
        
        if((head) == nullptr) (head) = root;
        
        if((previous) != nullptr){
            (previous)->right = root;
            root->left = (previous);
        }
        
        (previous) = root;
        recur(root->right, head, previous);
        
        
    }
    Node * bToDLL(Node *root)
    {
        Node* head = nullptr;
        Node* previous = nullptr;
        recur(root, head, previous);
        return head;
    }
};