class Solution {
public:
    TreeNode* recur(vector<int> &inorder, vector<int> &postorder, unordered_map<int, int> &inorder_map, int n, int i, int j){
        if(i > j) return nullptr;
        //if(n <0) return nullptr;
        int inroot = 0;
        int postroot = 0;
        bool gotit = false;
        for(int k=n; k>=0; k--){
            if(inorder_map[postorder[k]] >= i && inorder_map[postorder[k]] <= j){
                gotit = true;
                postroot = k;
                inroot = inorder_map[postorder[k]];
                break;
            }
        }
        if(!gotit) return nullptr;
        TreeNode* root = new TreeNode(postorder[postroot]);
        root->left = recur(inorder, postorder, inorder_map, n-1, i, inroot-1);
        root->right = recur(inorder, postorder, inorder_map, n-1, inroot+1, j);
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int, int> inorder_map;
        for(int i=0; i<inorder.size(); i++){
            inorder_map[inorder[i]] = i;
        }
        TreeNode* root = recur(inorder, postorder, inorder_map, postorder.size()-1, 0, inorder.size()-1);
        return root;
    }
};