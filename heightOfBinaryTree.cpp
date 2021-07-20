//User function template for C++

/*
struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
    
    Node(int x){
        data = x;
        left = right = NULL;
    }
};
*/
class Solution{
    public:
    int recur(Node* root, int depth){
        if(root == nullptr)
            return depth;
        return max(recur(root->left, depth+1), recur(root->right, depth+1));
    }
    int height(struct Node* node){
        return recur(node, 0);
        
    }
};