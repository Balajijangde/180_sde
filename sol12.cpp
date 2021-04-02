class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        //transpose a matrix
        
        for(int line=0; line<matrix.size()-1; line++){
           for(int i=line; i<matrix.size(); i++){
                swap(matrix[line][i], matrix[i][line]);
            } 
        }
        
        //invert the rows
        for(int row=0; row<matrix.size(); row++){
            int initial = 0;
            int final = matrix.size()-1;
            while(initial < final){
                swap(matrix[row][initial++], matrix[row][final--]);
            }
        }
    }
};