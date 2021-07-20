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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> result;
        vector<int> partial;
        queue<pair<TreeNode*, int>> myqueue;
        if(root == nullptr)
            return result;
        int lastLevel = 0;
        myqueue.push({root, 0});
        while(!myqueue.empty()){
            TreeNode* current = myqueue.front().first;
            int level = myqueue.front().second;
            myqueue.pop();
            if(level == lastLevel){
                partial.push_back(current->val);
            }else{
                result.push_back(partial);
                partial.clear();
                lastLevel = level;
                partial.push_back(current->val);
            }
            if(current->left != nullptr)
                myqueue.push({current->left, level+1});
            if(current->right != nullptr)
                myqueue.push({current->right, level+1});
            
        }
        result.push_back(partial);
        return result;
    }
};