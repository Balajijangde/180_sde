class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    void dfs(int current, vector<int> &result, vector<bool> &visited, vector<int>* adj){
        result.push_back(current);
        visited[current] = true;
        for(int i=0; i<adj[current].size(); i++){
            if(!visited[adj[current][i]]){
                dfs(adj[current][i], result, visited, adj);
            }
        }
    }
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<int> result;
        vector<bool> visited (V, false);
        dfs(0, result, visited, adj);
        return result;
    }
};