class Solution {
public:
    void recur(TreeNode* root, int k, int &result, int &index){
        if(root == nullptr) return;
        if(result != -1) return;
        
        recur(root->left, k, result, index);
        
        if(index == k && result == -1){
            result = root->val;
            return;
        }else{
            index++;
            
        }
        recur(root->right, k, result, index);
    }
    int kthSmallest(TreeNode* root, int k) {
        int result = -1;
        int index = 1;
        recur(root, k, result, index);
        return result;
    }
};