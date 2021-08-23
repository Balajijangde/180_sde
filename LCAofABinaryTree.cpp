class Solution {
public:
    bool recur(TreeNode* root, TreeNode* p, TreeNode* q, TreeNode** result){
        if(root == nullptr) return false;
        bool left = recur(root->left, p, q, result);
        bool right = recur(root->right, p, q, result);
        bool current;
        if(root == p || root == q) current = true;
        else current = false;
        if((left && right) || (current && left) || (current && right)) (*result) = root;
        return left || right || current;
        
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* result; 
        recur(root, p, q, &result);
        return result;
    }
};