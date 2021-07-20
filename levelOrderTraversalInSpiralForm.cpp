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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        stack<TreeNode*> s1;
        stack<TreeNode*> s2;
        vector<vector<int>> result;
        vector<int> partial;
        if(root == nullptr)
            return result;
        s1.push(root);
        while(!s1.empty() || !s2.empty()){
            if(s2.empty()){
                while(!s1.empty()){
                    if(s1.top()->left != nullptr)
                        s2.push(s1.top()->left);
                    if(s1.top()->right != nullptr)
                        s2.push(s1.top()->right);
                    partial.push_back(s1.top()->val);
                    s1.pop();
                }
                
            }else{
                while(!s2.empty()){
                    if(s2.top()->right != nullptr)
                        s1.push(s2.top()->right);
                    if(s2.top()->left != nullptr)
                        s1.push(s2.top()->left);
                    partial.push_back(s2.top()->val);
                    s2.pop();
                    
                }
            }
            result.push_back(partial);
            partial.clear();
        }
        return result;
    }
};