class Solution {
public:
    void recur(TreeNode* root, bool &result, long low_limit, long high_limit){
        if(result == false) return;
        if(root == nullptr) return;
        if(root->left != nullptr){
            if(root->left->val >= root->val || root->left->val <= low_limit){
            result = false;
                return;
            }
            recur(root->left, result, low_limit ,root->val);
        }
        if(root->right != nullptr){
            if(root->right->val <= root->val || root->right->val >= high_limit){
            result = false;
                return;
            }
            recur(root->right, result, root->val, high_limit);
        }
        
        
        
    }
    bool isValidBST(TreeNode* root) {
        bool result = true;
        recur(root, result,(long) INT_MIN-1,(long) INT_MAX+1);
        return result;
    }
};