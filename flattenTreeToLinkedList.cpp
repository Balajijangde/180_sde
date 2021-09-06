class Solution {
public:
    TreeNode* findTail(TreeNode* root){
        if(root->left == nullptr && root->right ==nullptr) return root;
        return findTail(root->right);
    }
    void recur(TreeNode* root){
        if(root == nullptr) return;
        if(root->left == nullptr && root->right == nullptr) return;
        
        recur(root->left);
        recur(root->right);
        
        if(root->left != nullptr){
            findTail(root->left)->right = root->right;
            root->right = root->left;
            root->left = nullptr;
        }
        
        return;
        
    }
    void flatten(TreeNode* root) {
        recur(root);
        
    }
};