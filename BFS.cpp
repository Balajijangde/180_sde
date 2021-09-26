class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        queue<int> myqueue;
        vector<bool> visited (V, false);
        
        myqueue.push(0);
        visited[0]  = true;
        while(!myqueue.empty()){
            int last = myqueue.front();
            result.push_back(last);
            myqueue.pop();
            for(int i=0; i<adj[last].size(); i++){
                if(!visited[adj[last][i]]){
                    myqueue.push(adj[last][i]);
                    visited[adj[last][i]] = true;
                }
            }
        }
        return result;
    }
};