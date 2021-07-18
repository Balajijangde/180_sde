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
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> result;
        stack<TreeNode*> mystack;
        TreeNode* current = root;
        while(!mystack.empty() || current != nullptr){
            if(current != nullptr){
                mystack.push(current);
                current = current->left;
            }else{
                result.push_back(mystack.top()->val);
                current = mystack.top()->right;
                mystack.pop();
            }
        }
        return result;
        
    }
};