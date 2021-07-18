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
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        stack<TreeNode*> mystack;
        mystack.push(root);
        while(!mystack.empty()){
            TreeNode* current = mystack.top();
            mystack.pop();
            result.push_back(current->val);
            if(current->right != nullptr)
                mystack.push(current->right);
            if(current->left != nullptr)
                mystack.push(current->left);
        }
        return result;
    }
};