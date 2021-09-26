class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    void dfs(int current, int parent, vector<bool> &visited, bool &result, vector<int> *adj){
        if(result) return;
        visited[current] = true;
        for(int j=0; j<adj[current].size(); j++){
            if(adj[current][j] != parent){
                if(visited[adj[current][j]]){
                result = true;
                return;
            }else{
                dfs(adj[current][j], current, visited, result, adj);
            }
            }
            
        }
    }
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool> visited (V, false);
        bool result = false;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, -1, visited, result, adj);
            }
        }
        return result;
    }
};