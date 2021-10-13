class Solution
{
	public:
	void dfs(int current, vector<int> *adj, stack<int> &topo, vector<bool> &visited){
	    visited[current] = true;
	    for(int i=0; i<adj[current].size(); i++){
	        if(!visited[adj[current][i]]){
	            dfs(adj[current][i], adj, topo, visited);
	        }
	    }
	    topo.push(current);
	}
	void newdfs(int current, vector<vector<int>> &newadj, vector<bool> &newvisited){
	    newvisited[current] = true;
	    for(int i=0; i<newadj[current].size(); i++){
	        if(!newvisited[newadj[current][i]]){
	            newdfs(newadj[current][i], newadj, newvisited);
	        }
	    }
	}
	
    int kosaraju(int V, vector<int> adj[])
    {
        vector<bool> visited (V, false);
        stack<int> topo;
        for(int i=0; i<V; i++){
            if(!visited[i]){
                dfs(i, adj, topo, visited);
            }
        }
        //got the topo stack
        vector<vector<int>> newadj (V, vector<int> ());
        for(int j=0; j<V; j++){
            for(int k=0; k<adj[j].size(); k++){
                newadj[adj[j][k]].push_back(j);
            }
        }
        //inverted graph ready
        int counter = 0;
        vector<bool> newvisited (V, false);
        while(!topo.empty()){
            int i = topo.top();
            topo.pop();
            if(!newvisited[i]){
                counter++;
                newdfs(i, newadj, newvisited);
            }
        }
        return counter;
    }
};