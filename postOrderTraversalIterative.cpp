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
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> result;
        if(root == nullptr)
            return result;
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        s1.push(root);
        while(!s1.empty()){
            TreeNode* current = s1.top();
            
            s2.push(current);
            s1.pop();
            if(current->left != nullptr)
                s1.push(current->left);
            if(current->right != nullptr)
                s1.push(current->right);
            
        }
        while(!s2.empty()){
            result.push_back(s2.top()->val);
            s2.pop();
        }
        return result;
    }
};