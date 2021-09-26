class Solution {
  public:
    // Function to detect cycle in a directed graph.
    bool dfs(int current, vector<bool> &visited, vector<bool> &dfsvisited, vector<int> *adj){
        visited[current] = true;
        dfsvisited[current] = true;
        
        for(int i=0; i<adj[current].size(); i++){
            if(dfsvisited[adj[current][i]]) return true;
            else if(!visited[adj[current][i]]){
                if(dfs(adj[current][i], visited, dfsvisited, adj)) return true;
            }
        }
        dfsvisited[current] = false;
        return false;
    }
    bool isCyclic(int V, vector<int> adj[]) {
        vector<bool> visited (V, false);
        vector<bool> dfsvisited(V, false);
        for(int i=0; i<V; i++){
            if(!visited[i]){
                if(dfs(i, visited, dfsvisited, adj)){
                    return true;
                }
            }
        }
        return false;
    }
};