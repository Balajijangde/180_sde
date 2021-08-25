class Solution {
public:
    TreeNode* recur(vector<int>& preorder, unordered_map<int, int> &inorder_map, vector<int> &inorder, int n, int i, int j){
        if(i>j) return nullptr;
        if(n >= preorder.size()) return nullptr;
        bool gotThat = false;
        int preRoot = 0;
        for(int q=n; q<preorder.size(); q++){
            if(inorder_map[preorder[q]] >= i && inorder_map[preorder[q]] <= j){
                preRoot = q;
                gotThat = true;
                break;
            }
        }
        if(!gotThat) return nullptr;
        int inRoot = inorder_map[preorder[preRoot]];
        TreeNode* root = new TreeNode(preorder[preRoot]);
        root->left = recur(preorder, inorder_map, inorder, preRoot+1, i, inRoot-1);
        root->right = recur(preorder, inorder_map, inorder, preRoot+1, inRoot+1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int, int> inorder_map;
        for(int i=0; i<inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        TreeNode* root = recur(preorder, inorder_map, inorder, 0, 0, inorder.size()-1);
        return root;
        
    }
};