class Solution {
public:
    bool recur(TreeNode* p, TreeNode* q, bool &result){
        if(p == nullptr && q == nullptr){
            return true;
        }else if(p == nullptr || q == nullptr){
            return result = false;
        }
        bool left = recur(p->left, q->left, result);
        bool right = recur(p->right, q->right, result);
        bool current = p->val == q->val;
        return result = left && right && current;
        
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        bool result = true;
        recur(p, q, result);
        return result;
    }
};