/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string result;
        queue<TreeNode*> iterator;
        if(root == nullptr) return result;
        
        iterator.push(root);
        result += to_string(root->val);
        TreeNode* last = iterator.front();
        iterator.pop();
        iterator.push(last->left);
        iterator.push(last->right);
        
        while(!iterator.empty()){
            TreeNode* last = iterator.front();
            iterator.pop();
            result.push_back(',');
            if(last == nullptr){
                result.push_back('#');
                continue;
            }
            result += to_string(last->val);
            iterator.push(last->left);
            iterator.push(last->right);
        }
        return result;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.length() == 0) return nullptr;
        vector<int> nums;
        
        int start = 0;
        for(int i=0; i<data.size(); i++){
            if(data[i] == ','){
                string element = data.substr(start, i-start);
                if(element == "#"){
                    nums.push_back(INT_MIN);
                }else{
                    int num = stoi(data.substr(start, i-start));
                    nums.push_back(num);
                }
                start = i+1;
            }
        }
        nums.push_back(INT_MIN);
        int array_pointer = 0;
        TreeNode* root = new TreeNode(nums[0]);
        queue<TreeNode*> iterator;
        iterator.push(root);
        
        while(!iterator.empty()){
            TreeNode* lastNode = iterator.front();
            iterator.pop();
            if(nums[++array_pointer] == INT_MIN){
                lastNode->left = nullptr;
            }else{
                lastNode->left = new TreeNode(nums[array_pointer]);
                iterator.push(lastNode->left);
            }
            
            if(nums[++array_pointer] == INT_MIN){
                lastNode->right = nullptr;
            }else{
                lastNode->right = new TreeNode(nums[array_pointer]);
                iterator.push(lastNode->right);
            }
        }
        return root;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));