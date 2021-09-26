class Solution
{
	public:
	//Function to return list containing vertices in Topological order. 
	void dfs(int current, int V, vector<int> *adj, stack<int> &mystack, vector<bool> &visited){
	    visited[current] = true;
	    for(int i=0; i<adj[current].size(); i++){
	        if(!visited[adj[current][i]]){
	            dfs(adj[current][i], V, adj, mystack, visited);
	        }
	    }
	    mystack.push(current);
	}
	vector<int> topoSort(int V, vector<int> adj[]) 
	{
	    vector<bool> visited(V, false);
	    vector<int> result;
	    stack<int> mystack;
	    for(int i=0; i<V; i++){
	        if(!visited[i]){
	            dfs(i, V, adj, mystack, visited);
	        }
	    }
	    while(!mystack.empty()){
	        result.push_back(mystack.top());
	        mystack.pop();
	    }
	    return result;
	    
	}
};