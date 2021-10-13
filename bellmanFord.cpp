class Solution {
public:
	int isNegativeWeightCycle(int n, vector<vector<int>>edges){
	    vector<int> visited (n, 1e8);
	    visited[0] = 0;
	    
	    for(int i=0; i<n-1; i++){
	        for(int j=0; j<edges.size(); j++){
	            if(visited[edges[j][0]] + edges[j][2] < visited[edges[j][1]]){
	                if(visited[edges[j][0]] + edges[j][2] >= 1e8){
	                    visited[edges[j][1]] = 1e8;
	                }else{
	                    visited[edges[j][1]] = visited[edges[j][0]] + edges[j][2];
	                }
	            }
	        }
	    }
	    //relaxed n-1 times
	    
	    for(int i=0; i<edges.size(); i++){
	        if(visited[edges[i][0]] + edges[i][2] < visited[edges[i][1]]){
	            return 1;
	        }
	    }
	    return 0;
	}
};