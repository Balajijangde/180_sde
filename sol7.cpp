class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        //columns = matrix[0].size();
        //rows = matrix.size();
        
        //traverse matrix once and respectively mark the dummy array
        bool col = true;
        for(int r=0; r<matrix.size(); r++){
            if(matrix[r][0] == 0)
                col = false;
            for(int c=1; c<matrix[0].size(); c++){
                if(matrix[r][c] == 0){
                        matrix[0][c] = 0;
                        matrix[r][0] = 0;
                }
            } 
        }
        
        //traverse matrix from last and make elements zero
        for(int r=matrix.size()-1; r>=0; r--){
            for(int c=matrix[0].size()-1; c>=1; c--){
                if(matrix[0][c] == 0 || matrix[r][0] == 0){
                    matrix[r][c] = 0;
                }
            }
            if(col == false)
                matrix[r][0] = 0;
        }
        
    }
};