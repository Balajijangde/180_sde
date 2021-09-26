class Solution {
public:
    void dfs(int current, bool parentValue, vector<vector<int>> &graph, vector<int> &visited, bool &result){
        if(!result) return;
        visited[current] = parentValue?0:1;
        for(int i=0; i<graph[current].size(); i++){
            if(visited[graph[current][i]] == -1){
                dfs(graph[current][i], !parentValue, graph, visited, result);
            }else{
                if((visited[graph[current][i]] == 1 && !parentValue) || (visited[graph[current][i]] == 0 && parentValue)){
                    result = false;
                    return;
                }
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int> visited (graph.size(), -1);
        bool result = true;
        for(int i=0; i<graph.size(); i++){
            if(visited[i] == -1){
                dfs(i, false, graph, visited, result);
            }
        }
        return result;
        
    }
};