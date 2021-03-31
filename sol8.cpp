class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> result;
        for(int i=1; i<=numRows; i++){
            vector<int> part;
            int initial = 1;
            for(int j=0; j<i; j++){
                
                if(j>0){
                    initial = initial * (i-j);
                    initial = initial / j;
                }
                part.insert(part.end(), initial);
            }
            result.insert(result.end(), part);
        }
        
        return result;
    }
};