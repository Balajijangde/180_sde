void recur(Node* root, Node*& pre, Node*& suc, int key, Node* prev){
    if(root == nullptr) return;
    
    //recurs left
    recur(root->left, pre, suc, key, root);
    //operate on node
    if(root->key < key){
        pre = root;
    }else if(root->key > key && suc == nullptr){
        suc = root;
    }
    //recurs right
    recur(root->right, pre, suc, key, root);
}
void findPreSuc(Node* root, Node*& pre, Node*& suc, int key)
{
    recur(root, pre, suc, key, nullptr);
    
}