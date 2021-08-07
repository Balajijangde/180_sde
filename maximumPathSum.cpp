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
    int recur(TreeNode* root, int &result){
        if(root == nullptr){
            return 0;
        }
        int left = recur(root->left, result);
        int right = recur(root->right, result);
        int res = max(max(left, right)+root->val, root->val);
        int last = left+right+root->val;
        if(max(res, last) > result) result=max(res, last);
        return res;
        
    }
    int maxPathSum(TreeNode* root) {
        int result = INT_MIN;
        recur(root, result);
        return result;
    }
};