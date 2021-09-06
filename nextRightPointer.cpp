class Solution {
public:
    void recur(Node* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        root->left->next = root->right;
        if(root->next != nullptr){
            root->right->next = root->next->left;
        }
        recur(root->left);
        recur(root->right);
    }
    Node* connect(Node* root) {
        recur(root);
        return root;
    }
};