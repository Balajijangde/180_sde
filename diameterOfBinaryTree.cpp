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
    int recur(TreeNode* root, int &diameter){
        if(root->left == nullptr && root->right == nullptr)
            return 0;
        int left = root->left!=nullptr?recur(root->left, diameter):-1;
        int right = root->right!=nullptr?recur(root->right, diameter):-1;
        if(left+right+2 > diameter)
            diameter = left+right+2;
        return max(left, right)+1;
    }
    int diameterOfBinaryTree(TreeNode* root) {
        if(root == nullptr)
            return 0;
        int diameter = 0;
        recur(root, diameter);
        return diameter;
    }
};