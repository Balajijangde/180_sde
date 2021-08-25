class Solution {
public:
    void recur(bool &result, TreeNode* lside, TreeNode* rside){
        if(lside == nullptr && rside == nullptr){
            return;
        }else if(lside == nullptr || rside == nullptr){
            result = false;
            return;
        } 
        if(lside->val != rside->val){
            result = false;
            return;
        }
        recur(result ,lside->right, rside->left);
        recur(result, lside->left, rside->right);
        return;
    }
    bool isSymmetric(TreeNode* root) {
        bool result = true;
        recur(result, root->left, root->right);
        return result;
    }
};