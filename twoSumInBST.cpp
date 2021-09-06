class Solution {
public:
    void inorder(TreeNode* root, unordered_set<int> &records, bool &result, int k){
        if(root == nullptr) return;
        if(result == true) return;
        
        if(records.find(k - (root->val)) != records.end()){
            result = true;
            return;
        }else{
            records.insert(root->val);
        }
        
        inorder(root->left, records, result, k);
        inorder(root->right, records, result, k);
        
        
    }
    bool findTarget(TreeNode* root, int k) {
        unordered_set<int> records;
        bool result = false;
        inorder(root, records, result, k);
        return result;
        
    }
};