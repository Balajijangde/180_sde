class Solution
{
	public:
	//Function to find the shortest distance of all the vertices
    //from the source vertex S.
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        vector<int> distance(V, INT_MAX);
        //vector<int> visited(V, false);
        //pair(distance, node)
        queue<pair<int, int>> myque;
        distance[S] = 0;
        myque.push({0, S});
        while(!myque.empty()){
            int node = myque.front().second;
            int dist = myque.front().first;
            myque.pop();
            //visited[node] = true;
            
            for(int i=0; i<adj[node].size(); i++){
                int currentNode = adj[node][i][0];
                int currentWeight = adj[node][i][1];
                
                int currentDistance = dist + currentWeight;
                if(currentDistance < distance[currentNode]){
                    distance[currentNode] = currentDistance;
                    myque.push({currentDistance, currentNode});
                }
                
            }
            
        }
        return distance;
    }
};