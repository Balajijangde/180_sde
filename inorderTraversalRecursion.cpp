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
class Solution {
public:
    void recur(TreeNode* root, vector<int> &result){
        
        //base case
        if(root->left == nullptr && root->right == nullptr){
            result.push_back(root->val);
            return;
        }
        //traverse left
        if(root->left != nullptr)
            recur(root->left, result);
        //traverse mid
        result.push_back(root->val);
        //traverse right
        if(root->right != nullptr)
            recur(root->right, result);
        
    }
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        recur(root, result);
        return result;
    }
};