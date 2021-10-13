class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    for(int q=0; q<matrix.size(); q++){
	        for(int i=0; i<matrix.size(); i++){
	            for(int j=0; j<matrix.size(); j++){
	                if(i != j && i != q && j != q){
	                    if(matrix[i][q] != -1 && matrix[q][j] != -1){
	                        if(matrix[i][j] >= 0){
	                            matrix[i][j] = min(matrix[i][j], matrix[i][q]+matrix[q][j]);
	                        }else{
	                            matrix[i][j] = matrix[i][q]+matrix[q][j];
	                        }
	                    }
	                    
	                }
	            }
	        }
	    }
	    
	}
};