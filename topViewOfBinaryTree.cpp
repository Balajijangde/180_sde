class Solution
{
    
    public:
    //Function to return a list of nodes visible from the top view 
    //from left to right in Binary Tree.
    
    vector<int> topView(Node *root)
    {
        vector<int> result;
        if(root == nullptr)
            return result;
        queue<pair<Node*, int>> myqueue;
        unordered_map<int, int> mymap;
        myqueue.push({root, 0});
        mymap.insert({0, root->data});
        int ll = 0;
        int rl = 0;
        while(!myqueue.empty()){
            Node* current = myqueue.front().first;
            int currentIndex = myqueue.front().second;
            myqueue.pop();
            if(mymap.find(currentIndex) == mymap.end()){
                mymap.insert({currentIndex, current->data});
            }
            if(current->left != nullptr){
                myqueue.push({current->left, currentIndex-1});
                if(currentIndex-1 < ll)
                    ll = currentIndex-1;
            }
            if(current->right != nullptr){
                myqueue.push({current->right, currentIndex+1});
                if(currentIndex+1 > rl)
                    rl = currentIndex+1;
            }
        }
        for(int i=ll; i<=rl; i++){
            result.push_back(mymap[i]);
        }
        return result;
    }

};