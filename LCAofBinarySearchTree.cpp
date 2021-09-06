class Solution {
public:
    bool recur(TreeNode* root, TreeNode** lca, TreeNode* p, TreeNode *q){
        if(root == nullptr) return false;
        bool left = recur(root->left, lca, p, q);
        bool right = recur(root->right, lca, p, q);
        bool current = (root==p||root==q)? true: false;
        bool result = (left && right) || (current && left) || (current && right);
        if(result){
            (*lca) = root;
            return true;
        }else{
            return (left || right || current);
        }
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        TreeNode* lca;
        recur(root, &lca, p, q);
        return lca;
    }
};