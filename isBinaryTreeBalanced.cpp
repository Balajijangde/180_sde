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
    int recur(TreeNode* root, bool &isBalanced){
        if(root == nullptr)
            return 0;
        int left = recur(root->left, isBalanced);
        int right = recur(root->right, isBalanced);
        if(abs(left-right) >= 2)
            isBalanced = false;
        return max(left, right)+1;
    }
    bool isBalanced(TreeNode* root) {
        bool isBalanced = true;
        recur(root, isBalanced);
        return isBalanced;
    }
};