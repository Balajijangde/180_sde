/* A binary tree node

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

//Function to return a list containing elements of left view of the binary tree.
vector<int> leftView(Node *root)
{
   // Your code here.
   vector<int> result;
   if(root == nullptr)
        return result;
    queue<pair<Node*, int>> myqueue;
    unordered_map<int, int> mymap;
    int limit = 0;
    myqueue.push({root, 0});
    while(!myqueue.empty()){
        Node* current = myqueue.front().first;
        int depth = myqueue.front().second;
        myqueue.pop();
        if(mymap.find(depth) == mymap.end())
            mymap.insert({depth, current->data});
        if(current->left != nullptr){
            myqueue.push({current->left, depth+1});
            if(depth+1 > limit)
                limit = depth+1;
        }
        if(current->right != nullptr){
            myqueue.push({current->right,depth+1});
            if(depth+1>limit)
                limit = depth+1;
        }
    }
    for(int i=0; i<=limit; i++){
        result.push_back(mymap[i]);
    }
    return result;
}