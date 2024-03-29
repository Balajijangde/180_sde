/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class BSTIterator {
public:
    vector<TreeNode*> mytree;
    int iterator = -1;
    void inorder(TreeNode* root){
        if(root == nullptr) return;
        inorder(root->left);
        mytree.push_back(root);
        inorder(root->right);
    }
    BSTIterator(TreeNode* root) {
        inorder(root);
    }
    
    int next() {
        return (mytree[++iterator])->val;
    }
    
    bool hasNext() {
        if(iterator + 1 >= mytree.size()) return false;
        else return true;
    }
};

/**
 * Your BSTIterator object will be instantiated and called as such:
 * BSTIterator* obj = new BSTIterator(root);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */