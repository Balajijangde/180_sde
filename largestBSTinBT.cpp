class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    vector<int> recur(Node* root, int &result){
        if(root == nullptr) return {INT_MAX, INT_MIN, 0, 1};
        
        vector<int> left = recur(root->left, result);
        vector<int> right = recur(root->right, result);
        
        if(left[1] < root->data && right[0] > root->data && (left[3] == 1 && right[3] == 1)){
            int final = left[2] + right[2] + 1;
            if(final > result) result = final;
            return {min(left[0], min(root->data, right[0])), 
            max(left[1], max(root->data, right[1])), 
            final, 1};
        }else{
            return {min(left[0], min(root->data, right[0])), 
            max(left[1], max(root->data, right[1])), 
            0, 0};
        }
    }
    int largestBst(Node *root)
    {
    	int result = 0;
    	recur(root, result);
    	return result;
    }
};