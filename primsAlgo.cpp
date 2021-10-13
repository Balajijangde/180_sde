class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        vector<int> key (V, INT_MAX);
        vector<bool> mst (V, false);
        vector<int> parent (V, -1);
        key[0] = 0;
        for(int counter = 0; counter < V-1; counter++){
            int lastNewNode;
            //find an excluded min node
            int minNode = INT_MAX;
            int minWeight = INT_MAX;
            for(int i=0; i<V; i++){
                if(!mst[i] && key[i] < INT_MAX){
                    if(minWeight > key[i]){
                        minNode = i;
                        minWeight = key[i];
                    }
                }
            }
            
            //add it to MST
            lastNewNode = minNode;
            mst[lastNewNode] = true;
            //cout<<"lastNewNode "<<lastNewNode<<endl;
            for(int i=0; i<adj[lastNewNode].size(); i++){
                int node = adj[lastNewNode][i][0];
                int weight = adj[lastNewNode][i][1];
                if(!mst[node] && weight < key[node]){
                    key[node] = weight;
                    parent[node] = lastNewNode;
                }
            }
            
            
        }
        int answer = 0;
        for(int i=1; i<V; i++){
            answer += key[i];
        }
        return answer;
    }
};