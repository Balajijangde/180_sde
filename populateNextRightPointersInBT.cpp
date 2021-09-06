class Solution
{
    public:
    Node* findNext(Node* root){
        if(root->nextRight == nullptr) return nullptr;
        else if(root->nextRight->left != nullptr) return root->nextRight->left;
        else if(root->nextRight->right != nullptr) return root->nextRight->right;
        else return findNext(root->nextRight);
    }
    void recur(Node* root){
        if(root == nullptr) return;
        else if(root->left == nullptr & root->right == nullptr) return;
        
        if(root->left != nullptr && root->right != nullptr){
            //connect both nodes
            root->left->nextRight = root->right;
            root->right->nextRight = findNext(root);
            recur(root->left);
            recur(root->right);
        }else if(root->left == nullptr){
            root->right->nextRight = findNext(root);
            recur(root->right);
        }else if(root->right == nullptr){
            root->left->nextRight = findNext(root);
            recur(root->left);
        }
    }
    void connect(Node *root)
    {
       recur(root);
    }    
      
};