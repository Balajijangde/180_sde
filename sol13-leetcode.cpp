class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int columns = matrix[0].size()   ;     
        int low = 0;
        int high = (rows*columns)-1;
        int mid = (low+high)/2;
        if(high == 0){
            if(matrix[0][0] == target)
                return true;
            else
                return false;
        }else if(high == 1){
            if(matrix[0][0] == target || matrix[high/columns][high%columns] == target)
                return true;
            else
                return false;
        }else{
            while(high-low>1){
            //element = matrix[mid/columns][mid%columns]
            if(matrix[mid/columns][mid%columns] == target || matrix[low/columns][low%columns] == target || matrix[high/columns][high%columns] == target)
                return true;
            else if(matrix[mid/columns][mid%columns] < target){
                low = mid;
                mid = (low+high)/2;
            }
            else{
                high = mid;
                mid = (low+high)/2;
            }
            
        }
        }
        
        
        return false;
    }
};